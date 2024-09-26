#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int longestConsecutiveSeq(vector<int>&nums)
{
    if(nums.size()==0) return 0;
    sort(nums.begin(),nums.end());
    int lastSmaller = INT_MIN;
    int count =0;
    int longest =1;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]-1==lastSmaller)
        {
            count +=1;
            lastSmaller=nums[i];
        }
        else if(nums[i]!=lastSmaller)
        {
            count =1;
            lastSmaller=nums[i];
        }
        else{}
        longest=max(longest,count);
    }
    return longest;
}
int longestConsecutiveSeqOptimal(vector<int>&nums)
{
    if(nums.size()==0) return 0;
    int longest =1;
    unordered_set<int> s;
    for(int i=0;i<nums.size();i++)
    {
        s.insert(nums[i]);
    }

    for(auto it:s)
    {
        if(s.find(it-1)==s.end())
        {
            int count =1;
            int x = it;
            while(s.find(x+1)!=s.end())
            {
                x +=1;
                count +=1;
            }
            longest=max(longest,count);
        }
    }




    return longest;
}

int main()
{
   vector<int> vec = {102,4,100,1,101,3,2,1,1};

   cout<<longestConsecutiveSeq(vec)<<endl;
   cout<<longestConsecutiveSeqOptimal(vec)<<endl;
    return 0;
}