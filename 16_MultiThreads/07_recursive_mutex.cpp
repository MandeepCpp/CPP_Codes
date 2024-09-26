
// it is same as mutex but same thread can lock one mutex multiple times using recursive_mutex
// if thread t1 first call lock/try_lock on recursive_mutex m1. then m1 is locked by t1 ,
// now as t1 is running in recursion , t1 can call lock/try_lock any number of times there is no issue.

// But if t1 have aquired 10 times lock/try_lock on mutex m1 then thread t1 wil have to unlock it 10 times
// othwerwise no other thread will be able to lock mutex m1
// it means recursive_mutex keeps the count how many times it was locked so that that times it should be locked
// 

#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


std::recursive_mutex m;
int buffer=0;

void recursionFun(char c, int loopfor)
{
    if(loopfor<0)
        return;
    m.lock();
    cout<<"lock by thread "<<c<<endl;
    cout<<c<<" "<<buffer++<<endl;
    recursionFun(c,--loopfor);
    m.unlock();
    cout<<"unlock by thread "<<c<<endl;
}
int main()
{
    std::thread t1(recursionFun,'M',5);
    std::thread t2(recursionFun,'N',5);
    t1.join();
    t2.join();

    return 0;
}