#include<iostream>
//#include<execution>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   std::vector<int> vec = {4,6,2,4,3,8,4,2,6,5,8,6,3};
   std::sort(std::execution::par,vec.begin(),vec.end());

   for(auto &e:vec)
   {
    cout<<e<<" ";
   }
    return 0;
}