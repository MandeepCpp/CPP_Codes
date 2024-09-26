// std::async

// it runs a function asynchronously( potentially a new thread) 
// returns a std::future that will hold the result

// there are three launch policies for creating task
// a. std::launch :: async
// b. std::launch:: deffered
// c. std::launch::async | std::launch::deffered

//how it works
// it automactically creates a thread(or picks from internal thread pool) and a promise object for us.
// then passes the std::promise object to thread function and return the associated std::future object
// when our passed argument function exits then its value will be set in this promise object.
// so eventually return value will be avilable in future object.


#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;



ull findEven(ull start, ull end)
{
    cout<<"func Thread ID: "<< std::this_thread::get_id()<<endl;
    ull EvenSum = 0;
    for (ull i = start; i <= end; i++)
    {
        if ((i & 1) == 0)
        {
            EvenSum += 1;
        }
    }
    return EvenSum;
}

int main()
{
    ull start = 0;
    ull end = 1900000000;
    
    cout<<"Main Thread ID: "<< std::this_thread::get_id()<<endl;
    cout << "Thread created if policy is std::async!!" << endl;
    //std::future<ull> EvenSum = std::async(std::launch::async,findEven,start,end);
    //cout << "Thread not created if policy is std::deffered!!" << endl;
    std::future<ull> EvenSum = std::async(std::launch::deferred,findEven,start,end);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Waiting for the result" << endl;

    cout << "Even Sum: " << EvenSum.get() << endl;
    cout << "completed" << endl;
    

    return 0;
}
