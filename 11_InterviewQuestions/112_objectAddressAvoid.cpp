// how to stop taking address of my obj.

#include<iostream>
using namespace std;


class Base
{
    int x;
    Base* operator &()  // second option
    {
        return this;
    }
    public:
    Base(){}
    //Base * operator &() = delete; //1st option
    
};
int main()
{
   Base b;
   cout<<&b<<endl;  //compile time error : address is not accessible 
    return 0;
}