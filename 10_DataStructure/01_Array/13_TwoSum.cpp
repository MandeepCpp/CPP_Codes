#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> twoSumbrute(vector<int> &nums, int target)
{ // O(n2)
    vector<int> vec;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                vec.push_back(i);
                vec.push_back(j);
            }
        }
    }
    return vec;
}
vector<int> twoSumbetter(vector<int> &nums, int target)
{
    map<int, int> mp;
    vector<int> vec;

    for (int i = 0; i < nums.size(); i++)
    {
        int current = nums[i];
        int more = target - current;
        if (mp.find(more) != mp.end())
        {
            vec.push_back(mp[more]);
            vec.push_back(i);
            return vec;
        }
        else
        {
            mp[current] = i;
        }
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int> &nums, int target)
{

    std::vector<std::pair<int, int>> num_with_indices;
    for (int i = 0; i < nums.size(); ++i)
    {
        num_with_indices.push_back({nums[i], i});
    }
    std::sort(num_with_indices.begin(), num_with_indices.end());
    int left = 0;
    int right = num_with_indices.size() - 1;
    while (left < right)
    {
        int sum = num_with_indices[left].first + num_with_indices[right].first;
        if (sum == target)
        {
            return {num_with_indices[left].second, num_with_indices[right].second};
        }
        else if (sum < target)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return {-1, -1};
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};

    std::vector<int> result1 = twoSumbrute(arr, 14);
    for (std::vector<int>::iterator it = result1.begin(); it != result1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    std::vector<int> result2 = twoSumbetter(arr, 14);
    for (std::vector<int>::iterator it = result2.begin(); it != result2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    std::vector<int> result3 = twoSumOptimal(arr, 14);
    for (std::vector<int>::iterator it = result3.begin(); it != result3.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}