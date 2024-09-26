#include<iostream>
#include<vector>
using namespace std;


void removeZeroToEnd(int arr[],int size)
{

    // time - O(2n)
    // space O(n)
    vector<int>vec;
 for(int i=0;i<size;i++)
 {
    if(arr[i]!=0)
    {
       vec.push_back(arr[i]);
    }
 }
 for(int i=0;i<vec.size();i++)
 {
    arr[i]=vec[i];
 }
 for(int i=vec.size()+1;i<size;i++)
 {
    arr[i]=0;
 }
}
void removeZeroToEndOptimal(int arr[],int size)
{

    int j=-1;
    for(int i=0;i<size;i++)
    {
      if(arr[i]==0)
      {
         j=i;
         break;
      }
    }
   if(j==-1)
   {
      return;
   }
    for(int i=j+1;i<size;i++)
    {
      if(arr[i]!=0)
      {
         swap(arr[i],arr[j]);
         j++;
      }
    }
}

void removeZeroToStartOptimal(int arr[],int size)
{

    int j=-1;
    for(int i=size-1;i>0;i--)
    {
      if(arr[i]==0)
      {
         j=i;
         break;
      }
    }
   if(j==-1)
   {
      return;
   }
    for(int i=j-1;i>0;i--)
    {
      if(arr[i]!=0)
      {
         swap(arr[i],arr[j]);
         j--;
      }
    }
}
int main()
{
   int arr1[]={0,1,0,2,3,2,0,0,4,5,1,0};
   int size1 = sizeof(arr1)/sizeof(arr1[0]);
   cout<<"before"<<endl;
   for(auto &e:arr1)
   {
    cout<<e<<" ";
   }
   cout<<endl<<"after"<<endl;
    //removeZeroToEnd(arr1,size1);
   // removeZeroToEndOptimal(arr1,size1);
    removeZeroToStartOptimal(arr1,size1);
  for(auto &e:arr1)
   {
    cout<<e<<" ";
   }
    return 0;
}