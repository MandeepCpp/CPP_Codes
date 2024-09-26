#include<iostream>
#include<map>
using namespace std;

int majorityElement(int arr[],int size)
{
    // map<int,int>mp;
    // for(int i=0;i<size;i++)
    // {
    //     mp[arr[i]]++;
    // }
    // for(auto &it:mp)
    // {
    //     if(it.second>(size/2))
    //         return it.first;
    // }
    // return -1;

    int count =0;
    int element=-1;
    for(int i=0;i<size;i++)
    {
        if(count==0)
        {
            element=arr[i];
            count=1;
        }
        else if(arr[i]==element)
        {
            count++;
        }
        else{
            count--;
        }
    }


    return element;
}


int main()
{
    int arr[] = {0,2,2,1,1,1,2,2};
    int len = sizeof(arr) / sizeof(int);

    cout<<majorityElement(arr,len)<<endl;
    return 0;
}