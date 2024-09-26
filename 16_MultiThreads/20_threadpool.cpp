#include<iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <random>
#include <chrono>
#include <sstream>
using namespace std;


template<typename T>
class SafeQueue
{
    std::queue<T> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
    public:
    bool empty()
    {
        std::unique_lock<mutex> lock(m_mutex);
        return m_queue.empty();
    }
    void push(T value)
    {
        std::unique_lock<mutex> lock(m_mutex);
        m_queue.push(value);
        m_cond.notify_one();
    }
    bool pop(T& value)
    {
        std::unique_lock<mutex> lock(m_mutex);
        while(m_queue.empty())
        {
            m_cond.wait(lock);
        }
        value = m_queue.front();
        m_queue.pop();
        return true;
    }

};

class ThreadPool
{
    std::vector<std::thread> m_threads;
    SafeQueue<std::function<void()>> m_queue;
    bool m_stop = false;
    void start(size_t numThreads)
    {
        for(size_t i=0;i<numThreads;i++)
        {
            m_threads.emplace_back([this]()
            {
                while(true)
                {
                    std::function<void()> task;
                    if(m_queue.pop(task))
                    {
                        task();
                    }
                    if(m_stop)
                    {
                        break;
                    }
                }
            });
        }
    }

    void stop() {
        m_stop = true;
        m_queue.push([] {}); // Add a dummy task to unblock the queue

        for (auto& thread : m_threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }
    public:
    ThreadPool(size_t numThreads)
    {
        start(numThreads);    
    }
    ~ThreadPool()
    {
        stop();    
    }
    void enqueue(std::function<void()> task) {
        m_queue.push(task);
    }
};

// A simulated task function
void simulatedTask(int id) 
{
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(1, 5);

    // int sleepTime = dis(gen);
    // std::cout << "Task " << id << " is running. (Sleep for " << sleepTime << " seconds)" << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(sleepTime));
    std::cout << "Task " << id << " is done." << std::endl;
}

std::string get_thread_id()
{
    auto myid = std::this_thread::get_id();
    std::stringstream ss;
    ss << myid;
    std::string mystr = ss.str();
    return mystr;
}

int main()
{
   const size_t numThreads = 4;
   const size_t numtasks = 10;

   ThreadPool pool(numThreads);

   for (size_t i = 0; i < numtasks; ++i) {
        pool.enqueue([i]()
                     {
                         printf("Task %d %s executed by thread \n", i, get_thread_id().c_str());
                        std::this_thread::sleep_for(std::chrono::seconds(10)); // Simulate some work
                     });
    }

    // Allow some time for tasks to complete before main thread ends
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "All tasks have been processed." << std::endl;

    return 0;
}