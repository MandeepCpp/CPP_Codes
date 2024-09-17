#include<iostream>
using namespace std;


template<typename T>
T fun(T x, T y)
{
    return x>y?x:y;
}
int main()
{
   cout<<fun<int>(100,40)<<endl;
   cout<<fun<char>('x','c')<<endl;
   cout<<fun<float>(3.5,3.7)<<endl;
    return 0;
}