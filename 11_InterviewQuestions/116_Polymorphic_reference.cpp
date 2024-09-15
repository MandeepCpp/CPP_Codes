#include <iostream>
using namespace std;

class Base
{
    int x;

public:
    virtual void print()
    {
        cout << "Base " << x << endl;
    }
};

class Derived : public Base
{
    int y;

public:
    virtual void print()
    {
        cout << "Derived " << y << endl;
    }
};

void fun(Base &b) // this function becomes polymorphic, object slicing
{
    b.print();
}
int main()
{
    Base b;
    fun(b);
    Derived d;
    fun(d);
    return 0;
}