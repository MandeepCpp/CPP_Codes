#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
using namespace std;

class myClass
{
private:
    int x;
    int y;
    static unique_ptr<myClass> instance; // static unique_ptr member which will point to the instance of this class
    static mutex mtx;
    myClass() {}

public:
    myClass(const myClass &obj) = delete; // delete copy const.
    myClass operator=(const myClass&obj) = delete; // delete = operator

    static myClass *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> guard(mtx); 
            if (instance == nullptr)
            {
                instance = make_unique<myClass>();
            }
            mtx.unlock();
        }
        return instance.get();

  
            // if (ptr == nullptr)
            // {
            //     ptr = new myClass();
            //     return ptr;
            // }
            // return ptr;

    }
};

unique_ptr<myClass> myClass::instance = nullptr;
mutex myClass::mtx;

void fun1()
{
    myClass *obj1 = myClass::getInstance();
    cout << "first " << obj1->getInstance() << endl;
}
void fun2()
{
    myClass *obj2 = myClass::getInstance();
    cout << "second " << obj2->getInstance() << endl;
}
int main()
{
    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();
    return 0;
}

// A singleton class is a special type of class in object-oriented programming 
// which can have only one object or instance at a time. 
// In other words, we can instantiate only one instance of the singleton class