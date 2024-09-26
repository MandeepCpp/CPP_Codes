
// #include<iostream>
// #include<mutex>
// #include<thread>

// using namespace std;

// std::mutex m1;
// std::mutex m2;
// void fun1()
// {
//     m1.lock();              //std::lock(m1,m2) to avoid deadlock
//     m2.lock();
//     cout<<"Critical section of fun 1"<<endl;
//     m1.unlock();
//     m2.unlock();
// }
// void fun2()
// {
//     m2.lock();          //std::lock(m2,m1)to avoid deadlock
//     m1.lock();
//     cout<<"Critical section of fun 2"<<endl;
//     m2.unlock();
//     m1.unlock();
// }



// int main()
// {
//    std::thread t1(fun1);
//    std::thread t2(fun2);
//    t1.join();
//    t2.join();
//     return 0;
// }

/*
Deadlock in threading occurs when two or more threads are waiting for each other to release resources, 
leading to a situation where none of the threads can proceed. 
This typically happens when each thread holds a resource the other threads need and are waiting for those resources to be released.
*/
#include <iostream>
#include <thread>
#include <mutex>

// Mutexes to simulate resources
std::mutex mutex1;
std::mutex mutex2;

// Function to be executed by thread1
void threadFunction1() {
    std::lock_guard<std::mutex> lock1(mutex1);
    std::cout << "Thread 1: Locked mutex1" << std::endl;
    
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::lock_guard<std::mutex> lock2(mutex2);
    std::cout << "Thread 1: Locked mutex2" << std::endl;
}

// Function to be executed by thread2
void threadFunction2() {
    std::lock_guard<std::mutex> lock2(mutex2);
    std::cout << "Thread 2: Locked mutex2" << std::endl;
    
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    std::lock_guard<std::mutex> lock1(mutex1);
    std::cout << "Thread 2: Locked mutex1" << std::endl;
}

int main() {
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    
    t1.join();
    t2.join();
    
    return 0;
}

/*
Explanation:
Mutexes: We have two mutexes, mutex1 and mutex2, which represent resources that threads need to access.

Thread Functions:

threadFunction1 locks mutex1 first and then tries to lock mutex2.
threadFunction2 locks mutex2 first and then tries to lock mutex1.
Deadlock Scenario:

If threadFunction1 locks mutex1 and threadFunction2 locks mutex2 at the same time, 
both threads will end up waiting indefinitely for the other to release the second mutex they need. 
This results in a deadlock.
Avoiding Deadlock
To avoid deadlock, you can follow these strategies:

Lock Ordering: Ensure all threads acquire locks in the same order. For example, always lock mutex1 before mutex2.

Timeouts: Use timed locks to ensure that threads do not wait indefinitely for resources.

Try-Lock: Use std::try_lock to attempt to acquire multiple locks without blocking.

Here’s a revised version of the code with a lock ordering strategy to avoid deadlock:

*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex1;
std::mutex mutex2;

void threadFunction1() {
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread 1: Locked mutex1 and mutex2" << std::endl;
}

void threadFunction2() {
    std::lock(mutex1, mutex2);
    std::lock_guard<std::mutex> lock1(mutex1, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(mutex2, std::adopt_lock);
    std::cout << "Thread 2: Locked mutex1 and mutex2" << std::endl;
}

int main() {
    std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    
    t1.join();
    t2.join();
    
    return 0;
}
