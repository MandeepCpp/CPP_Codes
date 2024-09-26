#include <iostream>

using namespace std;
void mergeArray(int arr1[],int arr2[], int len1,int len2, int arr3[])
{
    int i=0,j=0,k=0;
    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<len1)
    {
        arr3[k++]=arr1[i++];
    }
    while(j<len2)
    {
        arr3[k++]=arr2[j++];
    }
    
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {0,7, 8, 9};
    
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);

    int arr3[len1+len2];
    

    cout<<"Before: "<<endl;
    for(int i=0;i<len1;i++)
    {
        cout<<arr1[i];
    }
    cout<<endl;
    cout<<"Before: "<<endl;
    for(int i=0;i<len2;i++)
    {
        cout<<arr2[i];
    }
    cout<<endl;
    mergeArray(arr1, arr2, len1, len2,arr3);
    cout<<"After: "<<endl;
    for(int i=0;i<len1+len2;i++)
    {
        cout<<arr3[i];
    }
    cout<<endl;
    return 0;
}