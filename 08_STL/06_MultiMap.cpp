// std::multimap<T1,T2> m; where T1 is key type and T2 is value type
// std::multimap is associative container that store elements in key value combination
// while premitting multiple entries with the same key
// it is implment using self balance binary search tree(AVL/Red Black Tree)
// it store key value pair in sorted order on the basis of key .

// we do not have at() and [] functions to get element like we had in std::map

#include<iostream>
#include<map>
#include<string>
#include<functional>


using namespace std;


int main()
{
    std::multimap<string,int> m;
    m.insert(make_pair("Mandeep",40));
    m.insert(make_pair("Mandeep",20));
    m.insert(make_pair("Mandeep",30));
    m.insert(make_pair("Nav",11));
    m.insert(make_pair("Nav",22));
    m.insert(std::make_pair("Naman",458));

    for(const auto& e:m)
    {
        cout<<e.first<<" : "<<e.second<<endl;
    }
    cout<<"*******************"<<endl;
    auto range = m.equal_range("Mandeep");

    for(auto it = range.first;it!=range.second;it++)
    {
        cout<<it->first<<" : "<<it->second<<endl;
    }
cout<<"*******************"<<endl;
cout<<m.count("Nav")<<endl;

auto d = m.find("Nav");
d++;

 cout<<d->first<<" : "<<d->second<<endl;

    return 0;
}