#include<iostream>
using namespace std;

class Base
{
    public:
    static void print()
    {
        cout<<"Hello@!"<<endl;
    }
};
int main()
{
   Base::print();

   Base b1;
   b1.print();
    return 0;
}