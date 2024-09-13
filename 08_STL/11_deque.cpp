// std::deque is an indexed sequence container
// it allows fast insertion at both begening and end
// unlike vector, elements of deque are not stored contiguous
// it uses individual allocated fixed size array with additinal bookkeeping meaning index based access to deque must perform two pointer de-referece

// the storage of deque is automatically expanded and contracted as needed
//Expension of deque is cheaper than expension of vector.

// TIME COMPLEXITY:
// Random access - constant O(1)
// Insertion or removal of elements at the end or beginning - constant O(1)
// Insertion or removal of elements - linear O(n)


#include<iostream>

#include<deque>

using namespace std;

int main()
{
    std::deque<int> dq1 = {5,6,3,8,9};

    dq1.push_front(1);
    dq1.push_back(10);
    

    for(const auto & e:dq1)
    {
        cout<<e<<" ";
    }

    cout<<endl;

    dq1.pop_front();
    dq1.pop_back();
    
    for(const auto & e:dq1)
    {
        cout<<e<<" ";
    }

    cout<<endl;
}