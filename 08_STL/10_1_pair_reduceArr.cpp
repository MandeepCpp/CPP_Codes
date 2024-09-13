#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool myCompare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first<p2.first;
}

int main()
{
   int arr[]={10,16,7,14,5,3,12,9}; // reduce this array
   int size = sizeof(arr)/sizeof(arr[0]);
   for(int i=0;i<size;i++)
   {
    cout<<arr[i]<<" ";
   }
    cout<<endl;
   std::vector<pair<int,int>> vec;

   for(int i=0;i<size;i++)
   {
    vec.push_back(make_pair(arr[i],i));
   }

   std::sort(vec.begin(),vec.end(),myCompare);

   for(int i=0;i<vec.size();i++)
   {
    arr[vec[i].second]=i;
   }

   for(int i=0;i<vec.size();i++)
   {
    cout<<arr[i]<<" ";
   }

    return 0;
}