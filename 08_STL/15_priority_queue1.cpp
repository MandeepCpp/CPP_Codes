#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct CustomCompare {
    bool operator()(int lhs, int rhs) {
        return lhs < rhs; // Min-heap
    }
};

int main() {
    std::priority_queue<int, std::vector<int>, CustomCompare> pq;

    std::priority_queue<int, std::vector<int>, CustomCompare> pq1;

auto comp=[](const int& x, const int& y ){return x>y;};
    std::priority_queue<int,std::vector<int>,decltype(comp)> pq2(comp);

    // Adding elements to the priority queue
    pq2.push(10);
    pq2.push(20);
    pq2.push(5);

    // Displaying elements in the priority queue
    while (!pq2.empty()) {
        std::cout << pq2.top() << " ";
        pq2.pop();
    }

    return 0;
}
