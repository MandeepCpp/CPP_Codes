#include<iostream>
using namespace std;

class Base
{
    int x;
    public:
    Base(){cout<<"Constructor"<<endl;}
    ~Base(){cout<<"Destructor"<<endl;}
};
int main()
{
   cout<<"normal case"<<endl;

   Base *ptr = new Base();
   delete ptr;


   // placement new , only if i know the how much memory is needed


   cout<<"placement new case"<<endl;

   char * memory = new char [10*sizeof(Base)];

   Base *ptr1 = new (&memory[0]) Base();
   Base *ptr2 = new (&memory[4]) Base();
   Base *ptr3 = new (&memory[8]) Base();

    Base *ptr4 = new (&memory[12]) Base();

   ptr1->~Base();
   ptr2->~Base();
   ptr3->~Base();

ptr4->~Base();


    return 0;
}