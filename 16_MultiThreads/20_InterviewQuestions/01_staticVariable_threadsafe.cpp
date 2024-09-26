#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
// No, static variable is not thread safe
static int s=0;
std::mutex m;
void fun()
{
    int count =10000000;
    while(count--)
    {
        ++s;
    }
    cout<<s<<endl;
}
int main()
{
   std::thread t1(fun);
   std::thread t2(fun);

   t1.join();
   t2.join();
    return 0;
}