

#include<iostream>
#include<set>
#include<string>
//#include<functional>


using namespace std;

class Base
{
    public:
    int x;
    Base(int x=0):x(x) { cout<<"constructor"<<endl;}

    Base(const Base& rhs)
    {
        x=rhs.x;
        cout<<"copy constructor"<<endl;
    }

    
};

bool operator < (const Base& lhs, const Base& rhs) 
    {
        return lhs.x<rhs.x;
    }

int main()
{
    set<Base> obj;
    obj.insert(Base(1));  // two times objection creation and two process


    obj.emplace(1);    // single contruction
    

    return 0;
}
