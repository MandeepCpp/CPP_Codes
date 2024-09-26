// 1. the class unique_lock is a mutex ownership wrapper
// 2. can have different locking strategies
// 3. tansferof locking ownership  --> move ...not copy
//
// locking strategies
// --> defer_lock-----> do not acquire ownership of the mutex
// --> try_to_lock-----> try to acquire ownership of the mutex without blocking
// --> adopt_lock------> assume the calling thread already has ownership of the mutex

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex m1;
int buffer=0;

//example 1
void task1(const char c, int size)
{
    std::unique_lock<mutex> lock(m1); // automatically calls lock on mutex m1
    for(int i=0;i<size;i++)
    {
        buffer++;
        cout<<c<<" : "<<buffer<<endl;
    }
}
//example 2
void task2(const char c, int size)
{
    std::unique_lock<mutex> lock(m1, std::defer_lock); // does not call lock on mutex m1, beacuse used defer_lock
    lock.lock();// but then we have to explicitly tell to lock whenever we want to lock mutex m1
    for(int i=0;i<size;i++)
    {
        buffer++;
        cout<<c<<" : "<<buffer<<endl;
    }
}
int main()
{
   std::thread t1(task1,'M',5);
   std::thread t2(task1,'N',5);
   t1.join();
   t2.join();
   cout<<"------------------------"<<endl;
   std::thread t3(task2,'M',5);
   std::thread t4(task2,'N',5);
   t3.join();
   t4.join();
   cout<<"------------------------"<<endl;
   
    return 0;
}



