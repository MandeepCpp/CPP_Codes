// How delete[] Knows How Much To Deallocate In C++?
// ==>Over allocation (placement new ) explicitly desctrctor has to call
#include<iostream>

int const n = 10;

class Base
{
    public:
    int b_var;
};

int main()
{
    Base *bp = new Base[n];
    //char* tmp = (char*) operator new[](WORDSIZE + n * sizeof(Base));
    //Base *p = (Base*)(tmp + WORDSIZE);
    //*++
    // for(i=0;i<n;i++)
    // {
    //     new(p+1) Base();   --> placement new  [ call the constructors ]
    // }

    delete[] bp;

    // size_t n = *(size_t*) (char*p - WORDSIZE);
    // while(n--!=0)
    // {
    //     (bp + n)->~Base();
    // }
    // operator delete[] (char*)[bp-WORDSIZE]
    
}