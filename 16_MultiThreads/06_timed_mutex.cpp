// std::timed_mutex is blocked till timeout_time or the lock is aquired 
// returns true if success other wise false
// a. lock
// b. try_lock
// c. try_lock_for
// d. try_lock_untill
// unlock

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int amount = 0;
std::timed_mutex m;

void increment(int i)
{
    if (m.try_lock_for(std::chrono::seconds(1)))
    {
        ++amount;
        //std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << "Entered" << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " not entered" << endl;
    }
}

void increment1(int i) {
	auto now=std::chrono::steady_clock::now();
	if(m.try_lock_until(now + std::chrono::seconds(1))){
		++amount;
		std::this_thread::sleep_for (std::chrono::seconds(2));
		cout << "Thread " << i << " Entered" << endl;
		m.unlock();	
	}else{
		cout << "Thread " << i << " Couldn't Enter" << endl;
	}
}
int main()
{

    std::thread t1(increment1, 1);
    std::thread t2(increment1, 2);

    t1.join();
    t2.join();
    cout<<amount<<endl;

    return 0;
}