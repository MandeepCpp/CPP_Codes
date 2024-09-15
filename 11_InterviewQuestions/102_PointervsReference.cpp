#include<iostream>
using namespace std;
int main()
{
   int i=10;
   int &r = i; // refernce
   int *p = &i; // pointer
   int a =50;
   const int &constRef = a;

cout<<i<<" : "<<&i<<" : "<<&r<<" : "<< &p<<endl;

r = 90;
//constRef=100;  - can not be changed , complier error


cout<<i<<" : "<<&i<<" : "<<&r<<" : "<< &p<<endl;
    return 0;
}