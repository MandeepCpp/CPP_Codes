#include <iostream>
#include <vector>
#include <map>
using namespace std;

void twicOnceNumber(vector<int> &nums)
{

    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto &e : mp)
    {
        if (e.second == 1)
        {
            cout << e.first << endl;
        }
    }
}
int twicOnceNumberbetter(vector<int> &nums)
{
    int reqSize = (nums.size()+1)/2;
    int sum1 = (reqSize*(reqSize + 1));
    int sum2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum2 += nums[i];
    }
    cout << sum1<<endl;
    cout << sum2<<endl;
    return (sum1 - sum2);
}
void twicOnceNumberOptimal(vector<int> &nums)
{

    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result = result ^ nums[i];
    }
    cout << result<<endl;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};

    twicOnceNumber(arr);

    twicOnceNumberOptimal(arr);

    cout <<"single number" << twicOnceNumberbetter(arr) << endl;

    return 0;
}