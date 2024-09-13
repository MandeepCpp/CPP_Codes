// well tested and bunch of available functions in forward list in place of linked list

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    std::forward_list<int> fl1 = {8, 6, 5, 3, 9, 9, 6, 5, 4, 2};
    std::forward_list<int> fl2 = {6, 6, 3, 1, 0};

    auto it = fl1.begin();
    std::advance(it, 4);
    fl1.insert_after(it, 100);

    cout << "Example 1 : ";
    for (const auto &e : fl1)
    {
        cout << e << " ";
    }
    cout << endl;

    fl1.push_front(200);
    cout << "Example 2 : ";
    for (const auto &e : fl1)
    {
        cout << e << " ";
    }
    cout << endl;

    fl1.pop_front();
    cout << "Example 3 : ";
    for (const auto &e : fl1)
    {
        cout << e << " ";
    }
    cout<<endl;


    fl1.erase_after(fl1.begin());
    cout << "Example 4 : ";
    for(const auto& e: fl1)
    {
        cout<<e<<" ";
    }
    cout<<endl;


    fl1.merge(fl2);
    cout << "Example 5 : ";
    for(const auto& e: fl1)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    cout << "Example 6 : ";
    fl1.remove_if([](int n){return n>4;});
    for(const auto& e: fl1)
    {
        cout<<e<<" ";
    }


    return 0;
}