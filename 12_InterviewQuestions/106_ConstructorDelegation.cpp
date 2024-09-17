// constructor delegation

#include<iostream>

using namespace std;

class Base
{
    int _x,_y;
    public:
    Base():Base(0,0){}
    Base(int a):Base(a,0){}
    Base(int a, int b):_x(a),_y(b){}

    void print()
    {
        cout<<_x<<" "<<_y<<endl;
    }

};
int main()
{
Base b1;
Base b2(10);
Base b3(10,20);

b1.print();
b2.print();
b3.print();
}
