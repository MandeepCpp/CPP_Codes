// std::vector is a sequence container and also known as dynamic array
// its size can grow and shrink dynamically and no need to provide size at the compile time

// element access
// at(), [], front(), back(), data()


// modifiers:
// insert(), emplace(), push_back(), pop_back(), swap(), erase(), clear()


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main()
{
    std::vector<int> vec = {12,66,5,8,3};
    std::vector<int> vec1{12,66,5,8,3};

    std::cout<<vec.at(3)<<std::endl;
    //std::cout<<arr.at(6)<<std::endl; // will give error with eception , it is safe
    //std::cout<<arr[6]<<std::endl;  // will not throw an error and give garbage value

    std::cout<<vec.data()<<std::endl;  // will return pointer to arr

    vec.push_back(56);
    std::cout<<vec.at(3)<<std::endl;
    std::cout<<vec.at(5)<<std::endl;

    std::cout<<vec.size()<<std::endl;
    std::cout<<vec.capacity()<<std::endl;
    std::cout<<vec.max_size()<<std::endl;
    

    vec.reserve(1000);
    
    int m=3;
    int n=5;
    std::vector<vector<int>> matrix(m,vector<int>(n,10));




    std::vector<int> newVec;

    for(int i=0;i<10;i++)
    {
        newVec.push_back(i*3);
    }

    vector<int> ::iterator it1;

    for(auto it=newVec.begin();it!=newVec.end();it++)
    {
        cout<<*it<<" : ";
    }

    for(auto &e:newVec)
    {
        cout<<e;
    }
cout<<endl;
auto it2 = newVec.begin();
std::advance(it2,3);

newVec.insert(it2,555);
for(auto &e:newVec)
    {
        cout<<e<<" ";
    }
    return 0;
}