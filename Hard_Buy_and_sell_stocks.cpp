/*similar as the previous medium problem just one modification is that 
we have to keep one cap variable soo that jisme hame sirf 2 times hi usko buy and sell
karna hoga soo jab bhi sell ho jayega tab cap-1 hoga soo this is the approach*/


class Solution {

int max1(vector<int>& a,int ind,int n,int buy,int cap,vector<vector<vector<int>>>&dp){
    if(cap==0){
        return 0;
    }
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy][cap]!=-1){
        return dp[ind][buy][cap];
    }
    long profit=0;
    if(buy){
       profit=max(-a[ind]+max1(a,ind+1,n,0,cap,dp),max1(a,ind+1,n,1,cap,dp));
    }else{
        profit=max(a[ind]+max1(a,ind+1,n,1,cap-1,dp),max1(a,ind+1,n,0,cap,dp));
    }
    return dp[ind][buy][cap]=profit;

}

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return max1(prices,0,n,1,2,dp);
    }
};