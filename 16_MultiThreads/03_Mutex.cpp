// Race condition is a situation where two or more threads/process happened to change a common data at the same time.
// if there is a race condition then we have to protect it and the protected section is called critical section/region

// thread synchronisation will be done by mutex lock

#include <iostream>
#include <chrono>
#include   <mutex>
#include<thread>

using namespace std;

int myAmount =0;

std::mutex m;
void addMoney()
{
    m.lock();
    ++myAmount;
    m.unlock();
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    
    t1.join();
    t2.join();

    cout<<"My Amount : "<< myAmount<<endl;

    return 0;
}