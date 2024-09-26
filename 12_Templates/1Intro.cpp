#include<iostream>
using namespace std;




/*
What are Templates?
Templates enable you to create functions or classes that can operate with any data type. They are a way to achieve code generalization and reuse.

1. Function Templates
A function template works similarly to a normal function but is defined with a placeholder type.
2. Class Templates
Class templates allow you to create classes that can work with any data type. Here’s the syntax and

*/

template<typename T>
T fun(T x, T y)
{
    return x>y?x:y;
}

template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};


int main()
{
   cout<<fun<int>(100,40)<<endl;
   cout<<fun<char>('x','c')<<endl;
   cout<<fun<float>(3.5,3.7)<<endl;

    Box<int> intBox(123);
    Box<double> doubleBox(456.78);
    cout << intBox.getValue() << endl;      // Outputs: 123
    cout << doubleBox.getValue() << endl;   // Outputs: 456.78

    return 0;
}
