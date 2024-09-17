//functor works as function and achived by overloading operator () in some class

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// class Base
// {
//     int val;
//     public:
//     Base(){}
//     Base(int x):val(x){}

//     int operator ()(int m)
//     {
//         return m*val;
//     }
// };
// int main()
// {
//    Base b(50);
//    cout<<b(5)<<endl;
//    cout<<b(2)<<endl;
//     return 0;
// }

class isGreater
{
    int threshold;
    public:
    isGreater(int i): threshold(i){}

    bool operator()(int value)const
    {
        return value>threshold;
    }
};
int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int count = std::count_if(numbers.begin(),numbers.end(),isGreater(5));
    cout<<count<<endl;
    return 0;
}
