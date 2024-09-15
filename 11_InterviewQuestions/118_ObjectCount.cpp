#include<iostream>
using namespace std;


class myClass
{
    static int instance_count;
    static int destroy_count;
    public:
    myClass()
    {
        ++instance_count;
    }
    static int getInstanceCount()
    {
        return instance_count;
    }
    static int getdestroyCount()
    {
        return destroy_count;
    }
    ~myClass()
    {
        --instance_count;
        ++destroy_count;
    }
};
 int myClass::instance_count=0;
 int myClass::destroy_count=0;
int main()
{
   myClass obj1;
   cout<<myClass::getInstanceCount()<<endl;
   cout<<myClass::getdestroyCount()<<endl;
   myClass obj2;
   cout<<myClass::getInstanceCount()<<endl;
   cout<<myClass::getdestroyCount()<<endl;

   {
    myClass obj3;
    cout<<myClass::getInstanceCount()<<endl;
    cout<<myClass::getdestroyCount()<<endl;
   }
   myClass obj4;
   cout<<myClass::getInstanceCount()<<endl;
   cout<<myClass::getdestroyCount()<<endl;
    return 0;
}