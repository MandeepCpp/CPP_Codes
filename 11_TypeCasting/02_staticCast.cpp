#include<iostream>
#include<string>

using namespace std;

// purpose : perform a compile time checking for conversion between compatable types
// used with : basic data types , pointers and referance
// example : 

// it perform implicit conversion between types


// char * to int * is allowed in c but not with static_cast
class Int
{
    int x;
    public:
    Int(int x =0):x(x){cout<<"conversion constrcutor"<<endl;}

    operator string()
    {
        cout<<"conversion operator"<<endl;

        return to_string(x);
    }
};

// class Base 
// {
//     public:
//     Base(){}
// };
// class Derived : private Base()
// {

// };
int main()
{

/**********************first case*************************************/
    float f = 3.5;
    int a;

    a = f;
    a=static_cast<int>(f);  // both lines are same, but search is easy
    cout<<a<<" : "<< f<<endl;
/*********************************************************************/

/**********************second case*************************************/
    Int obj(3);
    string str1 = obj; // this is happening due to conversion operator defined, but it is better to do by below to make it good
    string str2 = static_cast<string>(obj);// both lines are same

    obj = 100;
    obj = static_cast<int>(100);
/*******************************************************************/

/**********************Third case*************************************/
    char c;
    int * ptr = (int*)&c; // risky cast, pass at complie time but fail at run time
    *ptr = 5;
 
    // int *iPtr = static_cast<int*>(&c); // will give complie time error
/*******************************************************************/


/**********************Fourth case*************************************/
    int * m= new int(10);
    void * v0 = static_cast<void*>(m);  // valid

    const int * m1= new int(10);
    //void * v1 = static_cast<void*>(m1);  // not valid
/*******************************************************************/



    




/**********************Fourth case*************************************/
   //Derived d;

   //Base * b = (Base*)(&d);  // allowed at complie time // risky

   //Base * b1 = static_cast(Base*)(&d); // will give complie time error  


   int i = 10;

    void *v = static_cast<void*>(&i);
    int *ip = static_cast<int*>(v);


    return 0;
}