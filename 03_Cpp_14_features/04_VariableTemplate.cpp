// TOPIC: Variable Template

// NOTES:
// 1. Before C++14 we had Function Template and Class Template, now we have Variable Template.

#include <iostream>
#include <complex>
using namespace std;

// EXAMPLE 1

template <typename T>
T pi = T(3.1415926535897932384626433L);

int main() {
   pi<char> = 'a';

    std::cout << pi<int> << endl;
    std::cout << pi<float> << endl;
    std::cout << pi<double> << endl;
    std::cout << pi<long double> << endl;
    std::cout << pi<char> << endl;
    return 0;
}