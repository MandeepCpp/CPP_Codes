// std::multiset<T> myset;

// std::multiset<T> is an associative container that contains a sorted set of duplicate objects of type key.
// it is usually implemented using Red- black Tree
// insertion, removal, search have logirathmic complexity
// if we want to store user defind data type in multiset then we will have to provide comapre function so that set can store them in sorted order.
// we can pass the order of sorting while constrcuting multiset object.


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

    bool operator > (const Person& rhs) const
    {
       return  age>rhs.age;
    }
    bool operator < (const Person& rhs) const
    {
       return  age<rhs.age;
    }
};

int main()
{
    std::multiset<int,std::greater<int>> m = {5,6,3,4,3,0,8,1};

    for(const auto& e:m)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    std::multiset<Person,std::less<>> p = {{50,"Kaur"},{30,"Mandeep"},{30,"Navpreet"},{50,"Kaur"}};

    for(const auto& e:p)
    {
        cout<<e.age<<" "<<e.name<<endl;
    }
  while(m.find(3)!=m.end())
  {
    m.erase(m.find(3));
  }
  for(const auto& e:m)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    return 0;
}