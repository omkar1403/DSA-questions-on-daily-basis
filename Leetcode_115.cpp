/*DISTINCT SUBSEQUENCE

isme we have to remember ki we have to take or notake the chars
so if they are equal then we take then both i-1,j-1 decreses else if we not take then just i-1,j decreases
and then else if they are not eqaul then we not take the number soo it remains i-1,j and that's all about


*/


class Solution {
    int min1(string s, string t,int i,int j,vector<vector<int>>&dp){
          
      if(j<0){
             return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=min1(s,t,i-1,j-1,dp)+min1(s,t,i-1,j,dp);
        }
        return dp[i][j]=min1(s,t,i-1,j,dp);

        }
    
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return min1(s,t,n-1,m-1,dp);
    }
};