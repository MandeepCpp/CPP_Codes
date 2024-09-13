// C++14 Features List

// BINARY LITERALS
//----------------
// 1.0 Now we can directly write Binary Literals.
// 2.0 GCC compiler had this feature but not standardized, now C++14 have standardized it.

    #include <iostream>
    using namespace std;

    int main() {

        int b1 = 0xFF;     // Binary 11111111
        cout << b1 << endl;

        int b2 = 0b11111111;  // 0b OR 0B
        cout << b2 << endl;

        int b3 = 0b1111'1111'1111'0101;  // 0b OR 0B
        cout << b3 << endl;

        return 0;
    }