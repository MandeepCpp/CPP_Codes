// function pointer store address of another function


#include<iostream>


using namespace std;


int add(int a, int b)
{
    return a+b;
}

// passing function pointer as parameter into another function

int fun1(int (*somefun)(int,int))
{
    int c = somefun(3,4);

    return c;
}

// A function that takes a callback function as an argument
void performOperation(int x, int y, int (*callback)(int, int)) {
    int result = callback(x, y);
    std::cout << "Operation result: " << result << std::endl;
}

// Example callback functions
int addition(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}


int main()
{
    int(*fun)(int,int) = &add;

    int res = (fun)(5,5);
    cout<<fun(3,5)<<endl;
    cout<<res<<endl;


    int c = fun1(add);
    cout<<c<<endl;


    // Using the callback
    performOperation(5, 3, addition);      // Output: Operation result: 8
    performOperation(5, 3, multiply); // Output: Operation result: 15


    
}