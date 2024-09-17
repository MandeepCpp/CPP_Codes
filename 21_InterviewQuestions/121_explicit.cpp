#include<iostream>
using namespace std;

class Base
{

    int x;
    public:
    Base()
    {
        x=0;
        cout<<"Default const"<<endl;
    }
    //explicit Base (int val)  // comp error
     Base (int val)
    {
        x=val;
        cout<<"para const"<<endl;
    }

    int getx()
    {
        return x;
    }
};

void func(Base obj)
{
    cout<<obj.getx()<<endl;
}
int main()
{
    Base obj1(4);
    func(obj1);

    Base obj2= 10;
    func(obj2);

    func(80);

    return 0;
}