// conditional variable

// A. notify other threads
// B. waiting for some conditions

// 1. condition variable allows running threads to wait on some condition and 
// and once those condition are met the waiting thread is notified using 
// : -> notify_one();
// : -> notify_all();
// 2. you need mutex to use condition variable
// 3. if some thread want to wait on some condition variable then it has to be do these things
// -> acquire the mutex lock using std::unique_lock<mutex> lock(m);
// -> execute wait, wait_for, or wait_untill. the wait operations automatcially release the mutex.
// and suspend the execution of the thread
// -> when the condition variable is notified , the thread is awakened and the mutex is automatically re-acquired
// the thread should then check the condition and resume waiting if the awake up was supress

// condition variable are used to synchronize two or more threads
// best use case of condition variable is product/consumer problem

#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance =0;
void addmoney(int money)
{
    std::lock_guard<mutex> lock(m);
    balance +=money;
    cout<<"current balance: "<<balance<<endl;
    cv.notify_one();
}

void withDrawMoney(int money)
{
    std::unique_lock<mutex> lock(m);
    cv.wait(lock,[](){return (balance!=0)?true:false;});
    if(balance>=money)
    {
        balance -=money;
        cout<<"amount deducted : "<< money<<" balance : "<<balance<<endl;
    }
    else
    {
        cout<<"amount not deducted"<< "balance : "<<balance<<endl;
    }
}



int main()
{
   std::thread t1(withDrawMoney,500);
   std::thread t2(addmoney,700);
   t1.join();
   t2.join();
    return 0;
}