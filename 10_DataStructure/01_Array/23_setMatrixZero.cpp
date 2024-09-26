#include<iostream>
#include<vector>
using namespace std;

void markzeroRow(std::vector<vector<int>> & nums,int row)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[row][i]!=0)
            nums[row][i]=-1;
    }
}
void markZeroCol(std::vector<vector<int>> & nums,int col)
{
    for(int i=0;i<nums[0].size();i++)
    {
        if(nums[i][col]!=0)
            nums[i][col]=-1;
    }
}
void setMatrixZeroBrute(std::vector<vector<int>>& nums)
{
    int m= nums.size();
    int n= nums[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(nums[i][j]==0)
            {
                markzeroRow(nums,i);
                markZeroCol(nums,j);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(nums[i][j]==-1)
            {
                nums[i][j]=0;
            }
        }
    }
}

void setMatrixZeroBetter(std::vector<vector<int>>& nums)
{
    int m= nums.size();
    int n= nums[0].size();
    int rowarr[n]={0};
    int colarr[m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(nums[i][j]==0)
            {
                rowarr[i]=1;
                colarr[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(rowarr[i]==1 ||colarr[j]==1)
            {
                nums[i][j]=0;
            }
        }
    }
}


int main()
{
   vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

   for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    cout<<"***************************************************"<<endl;
   //setMatrixZeroBrute(matrix);
   setMatrixZeroBetter(matrix);
   for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}