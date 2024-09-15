// run time polymorphism

#include<iostream>
using namespace std;


class Base
{
    public:
    virtual void fun()
    {
        cout<<"Base"<<endl;
    }

    virtual void myAddition()
    {
        cout<<"addBase"<<endl;
    }
};
class Dervied : public Base
{
    public:
    void fun()
    {
        cout<<"Derived"<<endl;
    }
};
int main()
{
   Base *b =  new Dervied();

    b->fun();

    b->myAddition();

    Dervied *d =  new Dervied();

    d->myAddition();        // if no overide function , then it will call base function , does not matter virtual


    return 0;
}
