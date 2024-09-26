#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size()));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                temp[i][j]=matrix[n-j][i];

            }
        }
        matrix = temp;
        
    }

int main()
{
   vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
   for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    cout<<"***************************************************"<<endl;
   rotate(matrix);
   for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
cout<<"***************************************************"<<endl;
    for(int i=0;i<2;i++)
        {
            for(int j=i+1;j<3;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        cout<<"***************************************************"<<endl;
   for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}