/*Soo isme hamne ek sell ke baad ek index chhodke hi buy kar sakte hai
soo hamne when we sell it then we just increment the index by ind+2 soo that it can move to next to next index */


int f(vector<int>& a,int ind,int n,int buy,vector<vector<int>>&dp){

    if(ind>=n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    long long profit=0;
    if(buy==1){
        
         return dp[ind][buy]=max(-a[ind]+f(a,ind+1,n,0,dp),f(a,ind+1,n,1,dp));
         }
    
     return dp[ind][buy]=max(a[ind]+f(a,ind+2,n,1,dp),f(a,ind+1,n,0,dp)); //here we add ind+2 in the function

}

int stockProfit(vector<int> &prices){
     int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,n,1,dp);
    
}