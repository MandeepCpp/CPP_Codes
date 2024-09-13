#include<iostream>
using namespace std;




/*
1. Structured Bindings:
    Allows unpacking of tuples and other structured types into individual variables easily.
*/
auto [a, b] = std::make_pair(1, 2);

/*
2. if with Initialization:
    Allows variable initialization within the condition of if and switch statements.
*/

if (auto result = someFunction(); result != 0) {
    // Use result
}

/*
3. constexpr if:
    Enables conditional execution of code at compile-time based on template parameters or constant expressions.


*/
template <typename T>
void process(T value) {
    if constexpr(std::is_integral_v<T>) {
        // Handle integral types
    } else {
        // Handle non-integral types
    }
}

/*
Improvements in constexpr:

Expanded support for constexpr, allowing more functions to be evaluated at compile-time.

*/

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}


std::filesystem::path p = "/path/to/file";
if (std::filesystem::exists(p)) {
    // Handle file existence
}


int main()
{
   
    return 0;
}










#include <iostream>
#include <string>
#include <type_traits>

// Type trait definitions
template <typename T>
struct is_string : std::false_type {};

template <>
struct is_string<std::string> : std::true_type {};

template <>
struct is_string<std::wstring> : std::true_type {};

template <typename T>
inline constexpr bool is_string_v = is_string<T>::value;

// Function template
template <typename T>
void process(T value) {
    if constexpr (is_string_v<T>) {
        std::cout << "String type: " << value << std::endl;
        // Handle string types here
    } else {
        std::cout << "Non-string type: " << value << std::endl;
        // Handle non-string types here
    }
}

int main() {
    process(std::string("Hello"));  // Output: String type: Hello
    process(std::wstring(L"World")); // Output: String type: World
    process(42);                   // Output: Non-string type: 42
    process(3.14);                 // Output: Non-string type: 3.14
}