#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void print(int val)
{
    cout<<val<<" ";
}
int main()
{
   vector<int> vec;

   for(int i=0;i<5;i++)
   {
    vec.push_back(i*3);
   }

   for(int i=0;i<vec.size();i++)
   {
    print(vec.at(i));
   }
    cout<<endl;
   for(auto &e:vec)
   {
    cout<<e<<" ";
   }
cout<<endl;

   for_each(vec.begin(),vec.end(),[](int n) {cout<<n<<" "; });
   cout<<endl;
   for_each(vec.begin(),vec.end(),print);

   cout<<endl;
    return 0;
}