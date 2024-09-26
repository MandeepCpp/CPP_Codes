#include<iostream>
using namespace std;

void rotateArraybykPlaceOptimalbyTime(int arr[],int size,int k)
{
  //O(size+k) -- time
  //o(k)---space

  k=k%size;

  int temp[k];
  for(int i=0;i<k;i++)
  {
    temp[i]=arr[i];
  }
  for(int i=k;i<size;i++)
  {
    arr[i-k]=arr[i];
  }
  for(int i=size-k;i<size;i++)
  {
    arr[i]=temp[i-(size-k)];
  }
   
}
void reverse(int arr[],int start,int end)
{
  while(start<=end)
  {
    int temp =arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    start++;
    end--;
  }
}
void rotateArraybykPlaceOptimalbySpace(int arr[],int size,int k)
{
 //O(2size) -- time
  //o(1)---space
  k=k%size;

  reverse(arr,0,size-k-1);
  reverse(arr,size-k,size-1);
  reverse(arr,0,size-1);
   
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
    //rotateArraybykPlaceOptimalbyTime(arr1,size1,3);
    rotateArraybykPlaceOptimalbySpace(arr1,size1,3);
  for(auto &e:arr1)
   {
    cout<<e<<" ";
   }
    return 0;
}