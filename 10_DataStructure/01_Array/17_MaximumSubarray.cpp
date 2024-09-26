#include<iostream>
#include<vector>
using namespace std;

int maximumSubArray(vector<int> &nums)
{
    vector<int>vec;
    int sum=0;
    int maximum=INT16_MIN;
    int start=0;
    int end=0;
    int tempstart=0;
     for (int i = 0; i < nums.size(); i++)
    {
        sum +=nums[i];
        if(sum>maximum)
        {
            maximum=sum;
            start =tempstart;
            end=i;
        }
        if(sum<0)
        {
            sum=0;
            tempstart= i+1;
        }

    }
    for(int  i=start;i<=end;i++)
    {
        vec.push_back(nums[i]);
    }
    for(auto &e:vec)
    {
        cout<<e<<" ";
    }
    cout<<endl;
    return maximum;
}
int main()
{
   vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
   cout<<maximumSubArray(vec)<<endl;

    return 0;
}