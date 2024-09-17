// #include<iostream>

// using namespace std;

// class Base
// {};
// int main()
// {

// }

// size of class and structor is 1 byte by default

#include<iostream>
using namespace std;

struct ABC
{};
class ABCD
{};
int main()
{
    ABC a;
    ABCD b;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    return 0;
}