// TOPIC: std::queue In C++

// NOTES:
// 0. std::queue class is a container adapter that gives the programmer the functionality of a queue
// 1. queue is FIFO (first-in, first-out) data structure.
// 2. std::queue provides only specific set of functions.
// 3. std::queue allows to push(insert) at back and pop(remove) from front.
// 4. std::queue gives front, back, push, pop, empty, size.




#include<iostream>

#include<queue>

using namespace std;

int main()
{
    std::queue<int> q1;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    

    while(!q1.empty())
    {
        cout<<q1.front()<<endl;
        q1.pop();
    }

    cout<<endl;
    cout<<"ww: " <<q1.front()<<endl;

    return 0;
}