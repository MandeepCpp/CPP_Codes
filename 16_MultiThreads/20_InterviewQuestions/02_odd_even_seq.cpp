#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class SequentialPrinter {
    int max;
    int count;
    std::mutex mtx;
    std::condition_variable cv;
    
    //std::binary_semaphore evenSem_;
    //std::binary_semaphore oddSem_;

public:
    SequentialPrinter(int max) : max(max), count(0) {}

    void printEven() {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= max) {
            //evenSem_.acquire();
            cv.wait(lock, [this]() { return count % 2 == 0; });
            if (count <= max) {
                std::cout << "Even: " << count << std::endl;
                ++count;
            }
            cv.notify_all();
            //oddSem_.release();  // Signal the odd semaphore
        }
    }

    void printOdd() {
        std::unique_lock<std::mutex> lock(mtx);
        while (count <= max) {
            cv.wait(lock, [this]() { return count % 2 != 0; });
           // oddSem_.acquire();
            if (count <= max) {
                std::cout << "Odd: " << count << std::endl;
                ++count;
            }
            cv.notify_all();
            //evenSem_.release();  // Signal the even semaphore
        }
    }
    
};

int main() {
    int max = 100;
    SequentialPrinter printer(max);

    std::thread evenThread(&SequentialPrinter::printEven, &printer);
    std::thread oddThread(&SequentialPrinter::printOdd, &printer);

    evenThread.join();
    oddThread.join();

    return 0;
}
