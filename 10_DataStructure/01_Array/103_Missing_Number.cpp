#include<iostream>

using namespace std;
int findMissingNumber(int arr[], int len)
{
    int sum1,sum2;
    sum1 = (len*(len+1))/2;
    for(int i =0;i<len;i++)
    {        
        sum2=sum2+arr[i];
    }
    return (sum1-sum2);
}
int main()
{
    int arr[] = {1,2,3,4,6,7,8,9,0};
    int len = sizeof(arr) / sizeof(int);
    int res = findMissingNumber(arr,len);
    
    cout<<"Missing number : "<<res<<endl;
    return 0;
}