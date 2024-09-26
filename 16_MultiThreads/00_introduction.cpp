
// in every application, there is a default thread which is main(), in side this we create other threads.
// A thread is also known as lightweight process.
// Idea is achieve parallelism by dividing a process into multiple threads.
// 

// ways to create threads in C++11

// 1. Funtion pointers
// 2. Lambda Funtions
// 3. Functors
// 4. member functions
// 5. static memeber functions


#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;


ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end)
{
    for(ull i = start;i<=end;i++)
    {
        if((i&1)==0)
        {
            EvenSum +=1;
        }
    }
}

void findOdd(ull start, ull end)
{
    for(ull i = start;i<=end;i++)
    {
        if((i&1)!=1)
        {
            OddSum +=1;
        }
    }
}

int main()
{
    ull start =0;
    ull end = 1900000000;
    auto startTime = high_resolution_clock::now();
    //findEven(start,end);
    //findOdd(start,end);
    std::thread t1(findOdd,start,end);
    std::thread t2(findEven,start,end);
    t1.join();
    t2.join();

    auto stopTime = high_resolution_clock::now();
    auto diff = duration_cast<microseconds>(stopTime-startTime);    

    cout<<"OddSum : " <<OddSum<<endl;
    cout<<"EvenSum : " <<EvenSum<<endl;
    cout<<diff.count()/1000000<<" sec"<<endl;

    return 0;
}