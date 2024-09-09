#include <iostream>
using namespace std;

template <typename T>
class MyUniquePtr
{
private:
    T *res;

public:
    MyUniquePtr(T *p = nullptr) : res(p)
    {
        cout << "Constructor" << endl;
    }
    MyUniquePtr(const MyUniquePtr &obj) = delete;
    MyUniquePtr &operator=(const MyUniquePtr &obj) = delete;

    // move const
    MyUniquePtr(MyUniquePtr &&obj)
    {
        res = obj.res;
        obj.res = nullptr; // transfer the ownership
    }

    // move assignment operator
    MyUniquePtr &operator=(MyUniquePtr &&obj)
    {
        if (this != &obj)
        {
            if (res)
            {
                delete res;
            }
            res = obj.res;
            obj.res = nullptr; // transfer the ownership
        }
        return *this;
    }

    T &operator*()
    {
        return *res;
    }
    T *operator->()
    {
        return res;
    }

    void reset(T *res_new = nullptr)
    {
        if (res)
        {
            delete res;
        }
        res = res_new;
    }

    ~MyUniquePtr()
    {
        cout << "Destructor" << endl;
        if (res)
        {
            delete res;
            res = nullptr;
        }
    }
};
int main()
{
    MyUniquePtr<int> ptr1(new int(10));
    //MyUniquePtr<int> ptr2(ptr1); compilation error
    //MyUniquePtr<int> ptr3 = ptr1 //compilation error

    MyUniquePtr<int> ptr4(new int(400));
    //ptr4 = ptr3;

    MyUniquePtr<int> ptr5 = std::move(ptr1);

    cout<<*ptr5<<endl;

    ptr1.reset(new int(50));

    return 0;
}