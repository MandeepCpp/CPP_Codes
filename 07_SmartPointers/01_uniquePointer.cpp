// TOPIC: Unique Pointer In C++

// NOTES:
// 0. unique_ptr is a class template.
// 1. unique_ptr is one of the smart pointer provided by c++11 to prevent memory leaks.
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer,
//    when unique_ptr object goes out of scope.
// 3. similar to actual pointers we can use -> and * on the object of unique_ptr,
//    because it is overloaded in unique_ptr class.
// 4. When exception comes then also it will de-allocate the memory hence no memory leak.
// 5. Not only object we can create array of objects of unique_ptr.

// OPERATIONS:
// release, reset, swap, get, get_deleter.

// PROGRAM:

#include <iostream>
#include <memory>
using namespace std;

class Base
{
    int x;

public:
    explicit Base(int val) : x{val} {}
    int getX() { return x; }
    ~Base() { cout << "Base Dest" << endl; }
};

int main()
{

    // Base *ptr = new Base(10);    // additional delete need to call
    // cout << ptr->getX() << endl;

    std::unique_ptr<Base> p1(new Base(10));  // additional no delete need to call // no exception safe
    cout << p1->getX() << endl;

    std::unique_ptr<Base> p2 = make_unique<Base>(20);  // additional no delete need to call // exception safe
    cout << p2->getX() << endl;

    //p1=p2;  // Fail : you can not copy ownership

    unique_ptr<Base> p3 = std::move(p2); // Pass: moving ownership allowed

    cout<<"BeforeReset: "<<p3->getX()<<endl;
    p3.reset();
    

    Base*p4 = p2.release();

    return 0;
}