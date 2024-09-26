#include<iostream>
#include<vector>
using namespace std;

std::vector<int> reArrangePosNeg(std::vector<int>& nums)
{
    // vector<int> res(nums.size(),0);
    // int posIndx=0;
    // int negIndx=1;
    // for(int i=0;i<nums.size();i++)
    // {
    //     if(nums[i]<0)
    //     {
    //         res[negIndx]=nums[i];
    //         negIndx +=2;            
    //     }
    //     else
    //     {
    //         res[posIndx]=nums[i];
    //         posIndx +=2;
    //     }
    // }
    // return res;

    vector<int> pos;
    vector<int> neg;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }

    if(pos.size()>neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1]=neg[i];
        }
        int idx = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++)
        {
            nums[idx]=pos[i];
            idx++;
        }
    }
    else
    {
        for(int i=0;i<pos.size();i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1]=neg[i];
        }
        int idx = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++)
        {
            nums[idx]=neg[i];
            idx++;
        }
    }



    return nums;
}


int main()
{
   vector<int> vec = {3,1,-2,-5,2,-4,-6};
   vector<int> res = reArrangePosNeg(vec);
   for(const auto & e: res)
   {
    cout<<e<<" ";
   }
    return 0;
}