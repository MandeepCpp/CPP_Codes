#include <iostream>
#include <thread>
using namespace std;

class mySingleton
{
    mySingleton(){}
   ~ mySingleton(){}

public:
    mySingleton(const mySingleton &) = delete;
    mySingleton &operator=(const mySingleton &) = delete;
    static mySingleton &getInstance()
    {
        static mySingleton obj;
        return obj;
    }
    void doSomething() const
    {
        std::cout << "Singleton instance doing something! : " << std::this_thread::get_id()<< std::endl;
    }
};

void threadFunction()
{
    mySingleton &obj1 = mySingleton::getInstance();
    obj1.doSomething();
}

int main()
{
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    std::thread t3(threadFunction);
    std::thread t4(threadFunction);
    std::thread t5(threadFunction);
    std::thread t6(threadFunction);
    std::thread t7(threadFunction);
    std::thread t8(threadFunction);
    std::thread t9(threadFunction);
    std::thread t10(threadFunction);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();

    return 0;
}