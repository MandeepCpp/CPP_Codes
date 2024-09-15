#include<iostream>
using namespace std;

#pragma pack(1)
struct Base
{
    char a;
    char b;
    int x;
    char y;
};

struct A
{
    int x;
    double b;
};
struct B
{
    int y;
    A a;
};

int main()
{
   cout<<"size of struct : "<< sizeof(Base)<<endl;
   cout<<"size of struct : "<< sizeof(A)<<endl;

   cout<<"size of struct : "<< sizeof(B)<<endl;
    return 0;
}