 /*
 A scoped_lock in C++ is a mechanism provided by the C++ Standard Library's threading support (such as the mutex header)
 for managing mutual exclusion in multi-threaded applications. Here's a summary of scoped_lock:

 Purpose: The purpose of a scoped_lock is to acquire ownership of one or more mutexes for a duration of a scope,
 ensuring that the mutexes are locked when the scoped_lock object is constructed and automatically released 
 when it goes out of scope.

 Usage: It is typically used in situations where multiple threads need to access shared resources concurrently,
 and the access to these resources must be synchronized to prevent data races and ensure thread safety.

 RAII (Resource Acquisition Is Initialization): Scoped_lock follows the RAII principle, 
 which ties the lifetime of a resource (in this case, mutex ownership) to the lifetime of an object. 
 When a scoped_lock object is created, it acquires the lock on the associated mutex(es), 
 and when it goes out of scope (e.g., at the end of a function or block), it automatically releases the lock(s),
 even in the presence of exceptions.

 Constructor: The constructor of scoped_lock takes one or more mutexes as arguments and locks them in a deadlock-safe manner.
 If any of the mutexes are already locked by another thread, 
 the constructor blocks until it can acquire ownership of all the mutexes without deadlocking.

 Ownership: A scoped_lock object owns the lock on the associated mutex(es) until it is destroyed, 
 meaning that the thread that owns the scoped_lock can safely access the protected resources. 
 Other threads attempting to lock the same mutex(es) will be blocked until the scoped_lock releases the lock(s).

 Preventing Deadlocks: Scoped_lock is designed to help prevent deadlocks by acquiring locks in a consistent and deadlock-safe order.
 It's important to acquire locks in the same order across all threads to avoid potential deadlocks.

 Overall, scoped_lock provides a convenient and safe way to manage mutex ownership 
 and ensure mutual exclusion in multi-threaded C++ applications, 
 helping to prevent data races and synchronization issues.

 if i understand correctly, 
 scoped_lock is a combination of std::lock and std::lock_guard. 
 
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
std::mutex m2;

void processData(int id) {
    // Acquire locks on m1 and m2 simultaneously
    std::scoped_lock lock(m1, m2);
    // Critical section
    std::cout << "Thread " << id << 
    ": Processing data with mutex1 and mutex2" << std::endl;
    // Perform processing here
}

int main() {
    const int numThreads = 50;
    std::thread threads[numThreads];
    // Create threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(processData, i);
    }
    // Join threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
    return 0;
}