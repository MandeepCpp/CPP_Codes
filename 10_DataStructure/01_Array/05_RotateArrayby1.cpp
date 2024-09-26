#include<iostream>
using namespace std;

void rotateArrayby1Place(int arr[],int size)
{
  int temp = arr[0];
  for(int i=1;i<size;i++)
  {
    arr[i-1]=arr[i];
  }
  arr[size-1]= temp;
   
}

int main()
{
   int arr1[]={0,1,2,3,4,5,6,7,8,9};
   int size1 = sizeof(arr1)/sizeof(arr1[0]);
   cout<<"before"<<endl;
   for(auto &e:arr1)
   {
    cout<<e<<" ";
   }
   cout<<endl<<"after"<<endl;
    rotateArrayby1Place(arr1,size1);
  for(auto &e:arr1)
   {
    cout<<e<<" ";
   }
    return 0;
}