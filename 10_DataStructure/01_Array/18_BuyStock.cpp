#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int buyAtPrice=INT_MAX;
        for(int i=0; i<prices.size(); i++){
            buyAtPrice = min(buyAtPrice, prices[i]);
            profit = max(profit, prices[i] - buyAtPrice); 
        }

        return profit;

}
int main()
{
   vector<int>vec = {7,1,5,3,6,4};
   cout<<"Buy with profit: "<<maxProfit(vec)<<endl;
    return 0;
}