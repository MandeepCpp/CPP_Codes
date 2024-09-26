#include<iostream>

using namespace std;
void reverseArray(int arr[], int len)
{
    for(int i =0;i<len/2;i++)
    {
        swap(arr[i],arr[len-i-1]);
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int len = sizeof(arr) / sizeof(int);
    cout<<"Before: "<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    reverseArray(arr,len);
    cout<<"After: "<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}