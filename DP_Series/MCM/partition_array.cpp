/*LEETCODE 1043
1)isme hame partition karne hai till it is less than minimum of n or i+k 
2)isme HAME length bhi maintain rakhni as well isme hame hame maximum element ko bhi maintain karna hai
3) we have to calculate the sum and call for the next recurrencce and then 
4)then we have to maintain one maxi1 for the actual value from that particular index*/





class Solution {
    int func(int i,int n,vector<int>& arr, int k,vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=INT_MIN;
        vector<int>ans;
        int maxi1=INT_MIN;
        int sum=0;
        int len=0;
        for(int j=i;j<min(n,i+k);j++){ //rememeber here we took minimum(n,i+k)
          ++len;                       //here we increased the length
          maxi=max(maxi,arr[j]);       //here we maintained the maximum element till i+k
               sum=(maxi*len)+func(j+1,n,arr,k,dp); ///here i made a mistake that sum=sum+maxi*len....X    soo i have to do that sum=maxi*len+func(j+1,...)
               maxi1=max(maxi1,sum);
            
        }
        return dp[i]=maxi1;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return func(0,n,arr,k,dp);
    }
};