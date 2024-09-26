#include<iostream>
using namespace std;

// the static variables in a class are shared by the objects.
// There can not be multiple copies of the same static variables for different objects.
// Also because of this reason static variables can not be initialized using constructors.

 class Base
 {
   static int x;
   public:
   static int y;
   Base()
   {
    cout<<"Inside constrcutor"<<endl;
   } 
   ~Base()
   {
    cout<<"Inside destrcutor"<<endl;
   }
   
 };

 int Base:: x = 10; // static variable has to initialized 
 int Base:: y = 100; // static variable has to initialized  
int main()
{
   Base b1;
   b1.y = 200;
   cout<<b1.y<<endl;
  

    int d = 0;
    if (d==0)
    {
        static Base b2;
    }

    cout<<"Main end"<<endl;
      return 0;
}

// a static variable inside a class should be initialized
// explicitly by the user using the class name and scope resolution operator outside the class