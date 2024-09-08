#include<iostream>
using namespace std;

constexpr int myConstInt = 42;
constexpr double pi= 3.14;

constexpr int product(int x, double y){return x*y;}

int main()
{
    constexpr int result = product(myConstInt, pi);
    cout<<result<<endl;
    return 0;
}

/*
both constexpr and consteval are used to indicate that a function or value can be evaluated at compile time, 
but they have different requirements and use cases. 

constexpr:
is a keyword that specifies that the value of a variable or the result of a function can be evaluated at compile time. 
cannot be called at runtime. it is stricker than constexpr
However, it does not require it. A constexpr function can be evaluated at runtime if necessary.

consteval:
is a more recent addition to C++ (introduced in C++20). 
It specifies that a function must be evaluated at compile time. 
If you attempt to use a consteval function with runtime values, the compiler will generate an error.

consteval int square(int x) {
    return x * x;
}

constexpr int x = square(5); // Evaluated at compile time
// int y = square(10); // This will cause a compile-time error

*/