// std::promise ==> used to set values or exceptions
// std::future ==> used to get values from promise
//              ==> ask promise if the value is available
//               ==> wait for the promise

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull EvenSum = 0;

void findEven(std::promise<ull> &&evenSumPromise, ull start, ull end)
{
    for (ull i = start; i <= end; i++)
    {
        if ((i & 1) == 0)
        {
            EvenSum += 1;
        }
    }
    evenSumPromise.set_value(EvenSum);
}

int main()
{

    ull start = 0;
    ull end = 1900000000;
    std::promise<ull> EvenSum;
    std::future<ull> EvenFuture = EvenSum.get_future();

    cout << "Thread created!!" << endl;
    std::thread t1(findEven, std::move(EvenSum), start, end);

    cout << "Waiting for the result" << endl;

    cout << "Even Sum: " << EvenFuture.get() << endl;
    cout << "completed" << endl;
    t1.join();

    return 0;
}
