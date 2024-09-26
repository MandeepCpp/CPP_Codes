/*
//C++20
A binary semaphore is a synchronization primitive used in concurrent programming
to manage access to a shared resource. 
It is a type of semaphore that only takes two values, 
typically 0 and 1, making it function similarly to a mutex (mutual exclusion) lock. 
Here’s a detailed explanation:

Binary Values: A binary semaphore can only be 0 or 1.

1 (or True): Indicates that the resource is available.
0 (or False): Indicates that the resource is unavailable or locked.


*/

#include <chrono>
#include <iostream>
#include <semaphore.h>
#include <thread>
 
// global binary semaphore instances
// object counts are set to zero
// objects are in non-signaled state
std::binary_semaphore
    smphSignalMainToThread{0},
    smphSignalThreadToMain{0};
 
void ThreadProc()
{
    // wait for a signal from the main proc
    // by attempting to decrement the semaphore
    smphSignalMainToThread.acquire();
 
    // this call blocks until the semaphore's count
    // is increased from the main proc
 
    std::cout << "[thread] Got the signal\n"; // response message
 
    // wait for 3 seconds to imitate some work
    // being done by the thread
    using namespace std::literals;
    std::this_thread::sleep_for(3s);
 
    std::cout << "[thread] Send the signal\n"; // message
 
    // signal the main proc back
    smphSignalThreadToMain.release();
}
 
int main()
{
    // create some worker thread
    std::thread thrWorker(ThreadProc);
 
    std::cout << "[main] Send the signal\n"; // message
 
    // signal the worker thread to start working
    // by increasing the semaphore's count
    smphSignalMainToThread.release();
 
    // wait until the worker thread is done doing the work
    // by attempting to decrement the semaphore's count
    smphSignalThreadToMain.acquire();
 
    std::cout << "[main] Got the signal\n"; // response message
    thrWorker.join();
}