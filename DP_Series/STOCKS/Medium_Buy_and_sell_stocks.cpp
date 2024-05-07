/*isme we have created a concept of buy and keep iterating suppose we have 
buy eqaul to 1 that means we have to buy the stock else we have 0 then we need to sell the stock and buy immediately after this
soo if (buy) then we will just subtract the current price soo profit=-price[ind]+max1(ind+1,0) it becomes 0 if we buy and then
find the maximum between if we dont buy max1(ind+1,1) it remains 1. ssoo this logic*/


class Solution {
int max1(vector<int>& a,int ind,int buy,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    long profit=0;
    if(buy){
       profit=max(-a[ind]+max1(a,ind+1,0,n,dp),max1(a,ind+1,1,n,dp));
    }else{
        profit=max(a[ind]+max1(a,ind+1,1,n,dp),max1(a,ind+1,0,n,dp));
    }
    return dp[ind][buy]=profit;
}


public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max1(prices,0,1,n,dp);
    }
};