/*Soo isme hamne first index and prev_index liya agar hamne take kiya then prev becomes index and index=index+1
if nottake then prev remain same and index+1 and current value should be greater than previous and id there is starting
index that means prev=-1 then we can take and we IMPORATNT:- "if we start from -1 then we have to take the dp[ind][prev+1] to avoid runtime
ERROR and we have to take the extra range of (n+1) because we are considering -1 as 0 that's why!"    */







class Solution {
int maxi(vector<int>& nums,int ind,int prev,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int len=maxi(nums,ind+1,prev,n,dp);     //NOT_TAKE
    if(prev==-1 || nums[ind]>nums[prev]){
        len=max(len,1+maxi(nums,ind+1,ind,n,dp));       //TAKE
    }
    return dp[ind][prev+1]=len;
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<vector<int>>dp(n,vector<int>(n+1,-1)); //here we took n+1 range for prev as i mentioned
     return maxi(nums,0,-1,n,dp);
    }
};