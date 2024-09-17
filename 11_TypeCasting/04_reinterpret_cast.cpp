



// it can typecast any pointer to any other pointer


#include<iostream>
using namespace std;


struct myStruct
{
    int x;
    int y;
    char c;
    bool b;
};
int main()
{
   myStruct obj;
   obj.x=5;
   obj.y=10;
   obj.c='M';
   obj.b=true;

    int *p = reinterpret_cast<int*> (&obj);
    cout<<*p<<endl;
    p++;
    cout<<*p<<endl;
    p++;
    char *c = reinterpret_cast<char*>(p);
    cout<<*c<<endl;
    c++;
    bool *b = reinterpret_cast<bool*>(c);
    cout<<*b<<endl;





    return 0;
}