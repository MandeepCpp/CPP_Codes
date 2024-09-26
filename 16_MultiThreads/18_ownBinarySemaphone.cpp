#include <mutex>
#include<thread>
#include <condition_variable>

using namespace std;
class BinarySemaphore {
public:
    BinarySemaphore(int initial = 1) : flag(initial) {}

    void wait() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return flag > 0; });
        --flag;
    }

    void signal() {
        std::unique_lock<std::mutex> lock(mtx);
        ++flag;
        cv.notify_one();
    }

private:
    std::mutex mtx;
    std::condition_variable cv;
    int flag;  // 0 or 1
};

int main() {
    BinarySemaphore sem(1); // initialize semaphore with 1

    // Example usage
    std::thread t1([&sem]() {
        sem.wait();
        // critical section
        sem.signal();
    });

    std::thread t2([&sem]() {
        sem.wait();
        // critical section
        sem.signal();
    });

    t1.join();
    t2.join();

    return 0;
}
