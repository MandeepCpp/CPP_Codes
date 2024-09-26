#include<iostream>
#include<vector>
using namespace std;


int linearSearch(int arr[],int size,int num)
{

    for(int i=0;i<size;i++)
    {
        if(arr[i]==num)
        {
            return i;
        }
    } 
    return -1;   
}

int main()
{
   int arr1[]={0,1,0,2,3,2,0,0,4,5,1,0};
   int size1 = sizeof(arr1)/sizeof(arr1[0]);
   
    cout<<linearSearch(arr1,size1,0)<<endl;
  
}