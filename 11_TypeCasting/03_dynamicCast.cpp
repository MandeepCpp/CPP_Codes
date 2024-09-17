#include<iostream>

using namespace std;


// to use dynamic cast , at least one virtual function in base class
// if the cast is successfull, dynamic_cast returns a value of type new_type
// if the cast fails and new_type is a pointer type, it returns a null pointer
// if the cast fails and new type is a reference , it throws an exception
class Base 
{
    virtual void print()
    {
        cout<<"Base"<<endl;
    }
};

class Derived1: public Base
{
     void print()
    {
        cout<<"Derived1"<<endl;
    }
};
class Derived2: public Base
{
     void print()
    {
        cout<<"Derived2"<<endl;
    }
};

int main()
{
    Derived1 d1;
    Base *b1 = dynamic_cast<Base*>(&d1);





    Derived1 * dp1 = dynamic_cast<Derived1*>(b1);
    Derived2 * dp2 = dynamic_cast<Derived2*>(b1);

    if (dp1 == nullptr)
        cout<<"bad cast 1 "<<endl;
    else
    {
        cout<<"good cast 1 "<<endl;
    }
    
    if (dp2 == nullptr)
        cout<<"bad cast 2 "<<endl;
    else
    {
        cout<<"good cast 2"<<endl;
    }
    return 0;
}