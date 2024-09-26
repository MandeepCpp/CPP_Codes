

// once a thread is started we wait for this thread to finish by calling join() function on thread object.
// double join will result into program termination
// if needed we should check thread is joinable before joining


// Detach is used to detach newly created thread from the parent thread.
// Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach will result into program termination
// if we have detached thread and main function is returning  then the detached thread executiuon is suspended.

#include <iostream>
#include <chrono>
#include<thread>

using namespace std;
void run(int count)
{
    while(count-->0)
    {
        cout<<"Mandeep Singh"<<endl;
    }

    std::this_thread::sleep_for(chrono::seconds(5));
}

int main()
{
    std::thread t1(run,12);
    cout<<"Main function"<<endl;
    t1.join();

    if(t1.joinable())
        t1.join();

    // if(t1.joinable())  // no wait....separate running
    //     t1.detach();

    cout<<"End"<<endl;

    return 0;
}