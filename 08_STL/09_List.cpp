// 1. This is double linked list what we know from C promming
// 2. List is sequence container that allow non contiguous memeory allocation
// 3. List is faster compared to other sequence containers(vector,forward_list,deque) in term of insertion, removal and moving element in any position provided
// well tested and bunch of available functions
// 

#include<iostream>

#include<list>

using namespace std;

int main()
{
    list<int> l1 = {5,9,6,3,7};
    list<int> l2 = {7,6,3,8,9};
    list<int>ls;
    ls.push_back(2);
    ls.emplace_back(12);
    ls.push_front(4);
    ls.emplace_front(14);

    for(const auto & e:l1)
    {
        cout<<e<<" ";
    }

    cout<<endl;

    l1.merge(l2);
    
    for(const auto & e:l1)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    for(const auto&e:ls)
    {
        cout<<e<<" ";
    }

    cout<<endl;
}