// ways to create threads in C++11

// 1. Funtion pointers
// 2. Lambda Funtions
// 3. Functors
// 4. member functions
// 5. static memeber functions

// if we multiple threads at the same time it does not guarantee which one will start first

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;


void fun(int x)
{
    while(x-->0)
    {
        cout<<x<<" ";

    }
    cout<<endl;
}

auto fun2 =[](int x){
    while(x-->0){
        cout<<x<<" ";
    }
    cout<<endl;
};
class FunctorBase
{
    public:
    void operator()(int x)
    {
        while(x-->0)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
class Base
{
    public:
    void run(int x)
    {
        while(x-->0)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
class StaticBase
{
    public:
    static void run(int x)
    {
        while(x-->0)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    /*****************first type - function pointer*****************************/
    cout<<"function pointer"<<endl;
    std::thread t1(fun,7);
    std::thread t2(fun,10);
    t1.join();
    t2.join();

    /*****************second type - lambda*****************************/
    cout<<"lambda"<<endl;
    std::thread t3([](int x){
    while(x-->0){
        cout<<x<<" ";
    }
    },15);
    t3.join();
    cout<<endl;
    /******************third type - functor*****************************/
    cout<<"functor"<<endl;
    std::thread fct(FunctorBase(),10);
    fct.join();

    /******************fourth type - non static function*****************************/
    cout<<"non static function"<<endl;
    Base b;
    std::thread t4(&Base::run,&b,10);

    t4.join();


    /******************fifth type - static function*****************************/
    cout<<"static function"<<endl;
    std::thread st4(&StaticBase::run,10);
    st4.join();

    return 0;
}