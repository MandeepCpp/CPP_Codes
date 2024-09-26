// it is very light wight wrapper for owning mutex on scoped basis
// it aquires mutex lock the moment you create the object of lock_guard
// it automactically removes the lock while goes out of scope
// you can not explicitly unlock the lock_guard
// you can not copy lock_guard

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

std::mutex m1;
int buffer=0;

void task(const char c, int size)
{
    std::lock_guard<mutex> lock(m1);
    for(int i=0;i<size;i++)
    {
        buffer++;
        cout<<c<<" : "<<buffer<<endl;
    }
}
int main()
{
   std::thread t1(task,'M',5);
   std::thread t2(task,'N',5);
   t1.join();
   t2.join();

   
    return 0;
}