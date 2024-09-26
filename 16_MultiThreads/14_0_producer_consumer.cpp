/*
Producer Consumer or bounded buffer problem
The problem Statement :
--> Producer will produce and consumer will consume with synchronization of a common buffer
--> untill Producer thread produces any data , consumer thread can not consume
--> thread will use condition_variable to notify each other
--> we need mutex if we use condition_variable beacuse CV waits on mutex.
--> this is one of the example of Producer Consumer.

Producer thread steps:
--> lock the mutex, if success then go ahead otherwise wait for mutex to get free
-->check if buffer is full and if it is full then unlock the mutex and sleep, if not then go ahead and produce the data.
--> insert item into buffer
-->unlock the mutex
--> notify the consumer

Consumer thread steps:
--> lock the mutex, if success then go ahead otherwise wait for mutex to get free
--> check if the buffer is empty and if it is empty then unlock the mutex and sleep, if not then go ahead and consume the data.
-->remove the item from buffer
--> unlock the mutex
--> notify the producer

Important: --> Producer and Consumer have to notify each other upon completion of their job.


*/

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>


using namespace std;
using namespace std::chrono;


std::mutex m;
std::condition_variable cv;

std::deque<int> buffer;

const unsigned int maxBufferSize = 50;

void producer(int val)
{
    while(val)
    {
        std::unique_lock<mutex> lock(m);
        cv.wait(lock,[](){return buffer.size()<maxBufferSize;});
        buffer.push_front(val);
        cout<<"Produced: "<<val<<endl;
        val--;
        lock.unlock();
        cv.notify_one();
    }
}
void consumer()
{
    while(true)
    {
        std::unique_lock<mutex> lock(m);
        cv.wait(lock,[](){return buffer.size()>0;});
        int val = buffer.back();
        buffer.pop_back();
        cout<<"Consumed: "<<val<<endl;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
   std::thread t1(producer,100);
   std::thread t2(consumer);


   t1.join();
   t2.join();
    return 0;
}