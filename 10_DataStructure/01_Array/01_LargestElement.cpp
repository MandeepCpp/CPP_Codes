#include<iostream>
using namespace std;

int largestNumber(int arr[],int size)
{
    int large = arr[0];
    for(int i=1;i<size-1;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }
    return large;
}



int main()
{
   int arr[]={3,7,5,6,1,2,5,4,8,6,3,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum element: "<<largestNumber(arr,size)<<endl;
    return 0;
}