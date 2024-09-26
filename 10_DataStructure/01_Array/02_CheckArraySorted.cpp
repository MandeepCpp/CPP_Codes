#include<iostream>
using namespace std;

int isArraySortedRotated(int arr[],int size)
{
   int cnt= 0;
   
    for(int i=1;i<size;i++)
    {
        if(arr[i-1]>arr[i])
        {
            cnt++;
        }
    }
    // if rotated
    if(arr[size-1]>arr[0])
    {
        cnt++;
    }
    

    return cnt<=1;
}





int main()
{
   int arr1[]={3,7,5,6,1,2,5,4,8,6,3,4,4,1};
   int arr2[]={2,3,5,5,6,8,9};
   int arr3[] ={3,4,5,1,2};
   int size1 = sizeof(arr1)/sizeof(arr1[0]);
   int size2 = sizeof(arr2)/sizeof(arr2[0]);
   int size3 = sizeof(arr3)/sizeof(arr3[0]);
   cout<<"is sorted or rotated : "<<isArraySortedRotated(arr1,size1)<<endl;
   cout<<"is sorted or rotated : "<<isArraySortedRotated(arr2,size2)<<endl;
   cout<<"is sorted or rotated : "<<isArraySortedRotated(arr3,size3)<<endl;
    return 0;
}