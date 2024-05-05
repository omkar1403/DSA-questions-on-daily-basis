/*  Here we have to do the 3 operations Soo when it comes to replace then we just replace and moving i-1,j-1  and
when it comes to deletion then we just delete one number and move i-1 and j remains as it is so when it comes to
inserting the element then we just kept i as it is as we insert element similar to the j soo and j moves to j-1 
and when both matches then we just put it as it is*/

class Solution {

int min1(string& s1, string& s2,int i,int j,vector<vector<int>>&dp){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=min1(s1,s2,i-1,j-1,dp);
    }
    return dp[i][j]=1+min(min1(s1,s2,i-1,j,dp),min(min1(s1,s2,i-1,j-1,dp),min1(s1,s2,i,j-1,dp)));
}

public:
    int minDistance(string word1, string word2) {
      int n=word1.length();
      int m=word2.length();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return min1(word1,word2,n-1,m-1,dp);
        } 
};