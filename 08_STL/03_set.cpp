// std::set<T> myset;

// std::set<T> is an associative container that contains a sorted set of unique objects of type key.
// it is usually implemented using Red- black Tree
// insertion, removal, search have logirathmic complexity
// if we want to store user defind data type in set then we will have to provide comapre function so that set can store them in sorted order.
// we can pass the order of sorting while constrcuting set object.


#include<iostream>
#include<set>
#include<string>
#include<functional>


using namespace std;

class Person
{
    public:
    float age;
    string name;

    bool operator < (const Person& rhs) const
    {
       return  age<rhs.age;
    }
};
int main()
{

    set<int> mySet = {1,3,6,8,4,3,9,4,6,2,4};
    set<int, std::greater<int>> mySet1 = {1,3,6,8,4,3,9,4,6,2,4};

    set<Person> p = {{30,"Mandeep"},{25,"Navpreet"},{50,"Kaur"}};

    for(const auto& e: mySet)
    {
        cout<<e<<" ";
    }
    
    cout<<endl;
    for(const auto& e: mySet1)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    for(const auto& e: p)
    {
        cout<<e.age<<":"<<e.name<<" ";
    }
    return 0;

}