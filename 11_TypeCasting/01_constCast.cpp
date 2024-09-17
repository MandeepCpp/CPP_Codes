// const_cast<T>(v) can be used to change the const or volatile qualifilers of pointers or references.
// where T must be a pointer, reference or pointer to member type

// purpose : adds or remove the const qualifier from a varibale
// used with : pointers and referance
// example : 

#include<iostream>

using namespace std;

void thirdPartyLib(int * x)
{
    int k = 10;
    cout<<k+(*x);
}

int main()

{


    const int a1 = 10;
    const int *b1 = &a1;

    int *d1 = const_cast<int *> (b1);
    *d1 = 15;  // invalid and undefined behaviour

    int a2 = 20;
    const int *b2 = &a1;

    int *d2 = const_cast<int *> (b2);
    *d2 = 30;
    /*****************************************************/


    const int x = 20;
    const int *px = &x;


    thirdPartyLib(const_cast<int*>(px));

 }