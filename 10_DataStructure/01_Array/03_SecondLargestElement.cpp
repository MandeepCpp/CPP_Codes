#include<iostream>
using namespace std;

int SecondlargestNumber(int arr[],int size)
{
    int large = arr[0];
    int secondLarge = -1;
    for(int i=1;i<size-1;i++)
    {
        if(arr[i]>large)
        {
            large=arr[i];
        }
    }

    for(int i=0;i<size;i++)
    {
        if(arr[i]>secondLarge && arr[i]!=large)
        {
            secondLarge=arr[i];
        }
    }

    return secondLarge;
}

int SecondlargestNumberOptimal(int arr[],int size)
{
    int large = arr[0];
    int secondLarge = -1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>large)
        {
            secondLarge=large;
            large=arr[i];
        }
        else if(arr[i]<large && arr[i]>secondLarge)
        {
             secondLarge = arr[i];
        }
    }    

    return secondLarge;
}



int main()
{
   int arr[]={3,7,5,6,1,2,5,4,8,6,3,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);
   // cout<<"Second largest element: "<<SecondlargestNumber(arr,size)<<endl;
    cout<<"Second largest element Optimal: "<<SecondlargestNumberOptimal(arr,size)<<endl;
    return 0;
}