#include<iostream>
using namespace std;


int func()
{
    cout<<"inside func"<<endl;
    return 1;
}

class Base
{
    public:
    static int var;
    Base()
    {
        func();
    }
};

int Base :: var = func(); // 1st option
Base b;  // 2nd option



int main()
{
   cout<<"Inside main"<<endl;
    return 0;
}