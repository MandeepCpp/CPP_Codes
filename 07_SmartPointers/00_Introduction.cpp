// 0. Smart pointer is a class which wraps a raw pointer, to manage the life time of the pointer.
// 1. The most fundamental job of smart pointer is to remove the chances of memory leak.
// 2. It makes sure that the object is deleted if it is not reference any more.

// TYPES:
// 1. unique_ptr : 
//    Allows only one owner of the underlying pointer.

// 2. shared_ptr : 
//    Allows multiple owners of the same pointer (Reference count is maintained).

// 3. weak_ptr : 
//    It is special type of shared_ptr which doesn't count the reference.

#include<iostream>
using namespace std;
template<typename T>
class MyInt {
    public:
        explicit MyInt(int *p=nullptr) { data = p; }
        ~MyInt() { delete data; }
        T& operator * () { return *data; }
    private:
        T *data;
};

int main() {
    //int* p = new int(10);
    MyInt<int> myint = MyInt<int>(new int(20));
    cout << *myint << endl;
    return 0;
}