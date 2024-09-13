// TOPIC: Generic Lambda

// NOTES:
// 1. Now in C++14 we have Generice/Polymorphic Lambda.

#include <iostream>
#include <complex>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

Lambdas are a powerful feature in C++ that allow for concise and readable code.
They are particularly useful in scenarios involving callbacks, custom algorithms, a
and situations where small, local functions are needed. 
By understanding and utilizing lambdas, 
C++ developers can write more expressive and maintainable code.
*/
int main() {

	// example 1 C++14
	auto add = [](auto x, auto y) { return x+y; };
	
	int a=1, b=2;
	std::string str1 = "CppNuts", str2="Rupesh";
	
	cout << add(a,b) << endl;
	cout << add(str1,str2) << endl;


	//example 
	//In this example, the lambda captures the variable factor by value
	//and it multiplies each element of the vector numbers by factor.
	std::vector<int> numbers = {1, 2, 3, 4, 5};
    int offset = 2.55;

    // Lambda to multiply each number by 'factor'
    
	std::for_each(numbers.begin(),numbers.end(),[offset](int &n)mutable {
		n= n* offset;
		offset++;

	});
    for (int n : numbers) {
        std::cout << n << " ";
    }
    cout<<offset<<endl;
	return 0;
}

/*
[ ] : No variables are captured.
[=] : All variables in the enclosing scope are captured by value.
[&] : All variables in the enclosing scope are captured by reference.
[x, &y] : x is captured by value, y is captured by reference.
[=, &y] : All variables are captured by value except y, which is captured by reference.
[this] : The lambda captures the this pointer by value.
*/