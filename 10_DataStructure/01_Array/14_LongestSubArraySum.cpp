#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubArraySum(vector<int> &nums, int K)
{ // O(n3)
    int len = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            vector<int> vec;
            for (int k = i; k < j; k++)
            {
                sum += nums[k];
                vec.push_back(nums[k]);
            }
            if (sum == K)
            {
                len = max(len, j - i);
                for (auto &e : vec)
                {
                    cout << e << " ";
                }
                cout << endl;
            }
        }
    }

    return len;
}
int longestSubArraySumBetter(vector<int> &nums, int K)
{
    map<int, int> preSumMp;
    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == K)
        {
            maxlen = max(maxlen, i + 1);
        }
        int rem = sum - K;
        if (preSumMp.find(rem) != preSumMp.end())
        {
            int len = i - preSumMp[rem];
            maxlen = max(maxlen, len);
        }
        if (preSumMp.find(sum) == preSumMp.end())
        {
            preSumMp[sum] = i;
        }
    }

    return maxlen;
}
int longestSubArraySumOptimal(vector<int> &nums, int K)
{//O(2n)
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int maxlen = 0;
    int n = nums.size();
    while (right < n)
    {
        while (left <= right && sum > K)
        {
            sum -= nums[left];
            left++;
        }
        if (sum == K)
        {
            maxlen = max(maxlen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += nums[right];
        }
    }
    return maxlen;
}
int main()
{
    vector<int> arr = {7, 1, 2, 3, 0, 0, 1, 1, -1, 1, -4, 2, 0, 3};

    cout << "Brute: " << longestSubArraySum(arr, 7) << endl;
    cout << "Better: " << longestSubArraySumBetter(arr, 7) << endl;
    cout << "Optimal: " << longestSubArraySumOptimal(arr, 7) << endl;

    return 0;
}