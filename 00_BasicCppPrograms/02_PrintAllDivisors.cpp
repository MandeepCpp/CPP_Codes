#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;



void printDivisors(int n)
{
    vector<int>vec;
    for(int i=1;i*i<=n;i++)         // start with 1 to avoid divison with 0
    {
        if(n%i==0)
        {
            vec.push_back(i);
            if((n/i)!=i)
            {
                vec.push_back(n/i);
            }
        }
    }

    std::sort(vec.begin(),vec.end());
    for(const auto& v:vec)
    {
        cout<<v<<" ";
    }
}






int main()
{
     int n=36;
     printDivisors(n);   
     return 0;
}