#include <iostream>
#include <set>
#include <vector>
using namespace std;

int findmissingNumbers(int arr[], int size)
{
    vector<int>vec;
    int idx=0;
    int value=0;
    for(int i=0;i<size-1;i++)
    {
        
        value=value^(arr[i]);
        idx=idx^(i+1);
    }
    idx=idx^size;
    return idx^value;
}

int missingNumber(vector<int>& nums) {
        int sum1 = (nums.size()*(nums.size()+1))/2;
    int sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            sum2 += nums[i];
        }
        return sum1-sum2;
    }

int main()
{
    int arr1[] = {1, 3, 4, 5, 6, 8, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout<<findmissingNumbers(arr1, size1)<<endl;

    return 0;
}