/*Just modify it to the k times*/

class Solution {

int f(vector<int>& a,int ind,int n,int buy,int k,vector<vector<vector<int>>>&dp){
    if(k==0){
        return 0;
    }
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy][k]!=-1){
        return dp[ind][buy][k];
    }
    long long profit=0;
    if(buy==1){
         return dp[ind][buy][k]=max(-a[ind]+f(a,ind+1,n,0,k,dp),f(a,ind+1,n,1,k,dp));
    }

     return dp[ind][buy][k]=max(a[ind]+f(a,ind+1,n,1,k-1,dp),f(a,ind+1,n,0,k,dp));
    

}

public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(prices,0,n,1,k,dp);
    }
};