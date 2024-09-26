#include<iostream>
#include<vector>
using namespace std;
vector<int> leaderArray(std::vector<int> & nums)
{
    vector<int> res;
    int maximum = INT_MIN;
    for(int i=nums.size()-1;i>=0;i--)
    {
        if(nums[i]>maximum)
        {
            res.push_back(nums[i]);
            
        }
        maximum= max(maximum,nums[i]);
    }
    return res;
}


int main()
{
   vector<int> vec = {10,22,12,3,0,6};
   vector<int> res = leaderArray(vec);
   for(const auto&e:res)
   {
    cout<<e<<" ";
   }
    return 0;
}