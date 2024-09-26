// 1. std::try_lock
// 2. std::mutex::try_lock
// 3. std::shared_lock::try_lock
// 4. std::timed_mutex::try_lock
// 5. std::unique_lock::try_lock
// 6. std::shared_mutex::try_lock
// 7. std::recursive_mutex::try_lock
// 8. std::shared_timid_mutex::try_lock
// 9. std::recursive_timid_mutex::try_lock

// try_lock() tries to lock the mutex. 
//  returns immediately. on sucesssful lock acquisition returns true otherwise false.
// if try_lock() is not able to lock the mutex , 
//  then it does not get blocked that why it is called non blocking
// if try_lock() is called again by the same thread which owns the mutex, 
//  the behaviour is undefined
// 


#include <iostream>
#include <chrono>
#include<mutex>
#include<thread>

using namespace std;

int counter =0;

std::mutex m;
void increaseTheCounter()
{
    for(int i =0; i<100000;++i)
    {
        if(m.try_lock())
        {
            ++counter;
            m.unlock();
        }
    }
}

int main()
{
    std::thread t1(increaseTheCounter);
    std::thread t2(increaseTheCounter);
    
    t1.join();
    t2.join();

    cout<<"My Amount : "<< counter<<endl;

    return 0;
}