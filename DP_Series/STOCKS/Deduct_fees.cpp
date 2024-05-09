
/*we have to deduct the fee for each transaction */

 int maxi(vector<int>& prices,int fee,int ind,int buy,int n,vector<vector<int>>&dp){
       if(ind==n){
        return 0;
       }
       if(dp[ind][buy]!=-1){
        return dp[ind][buy];
       }
       if(buy==1){
        return dp[ind][buy]=max(-prices[ind]+maxi(prices,fee,ind+1,0,n,dp),maxi(prices,fee,ind+1,1,n,dp));
       }
       return dp[ind][buy]=max(prices[ind]-fee+maxi(prices,fee,ind+1,1,n,dp),maxi(prices,fee,ind+1,0,n,dp));
    }
int maximumProfit(vector<int> &prices, int n, int fee)
{
	// Write your code here.
	 vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxi(prices,fee,0,1,n,dp);
}
