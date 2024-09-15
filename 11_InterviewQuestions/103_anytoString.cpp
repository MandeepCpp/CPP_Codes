//Any Data Type To String Conversion In C++

#include<iostream>
#include<string>
#include<sstream>

using namespace std;


template<typename T>
string xtos(T x)                              // x means any data type
{
    stringstream s;
    s<<x;
    return s.str();
}

int main()
{
    float f = 40.5;
    string sTemp1 = xtos(f);
    cout<<sTemp1<<endl;

    const char* ch = "40.5";
    string sTemp2 = xtos(ch);
    cout<<sTemp2<<endl;
    
}