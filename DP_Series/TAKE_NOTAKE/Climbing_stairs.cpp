/*isme hamne either 1 or 2 stairs karne the if we go below 1 or equal to 1 then we have to return 1 thats it*/



class Solution {
int solve(int i,vector<int>&dp){
  if(i<=0){
    return 1;
  }
  if(dp[i]!=-1){
    return dp[i];
  }
  int take=solve(i-1,dp);
  int notake=0;
  notake=solve(i-2,dp);
  
  return dp[i]=take+notake;
}

public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(n-1,dp);
    }
};