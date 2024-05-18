/*LEETCODE 1277
here we know that jo corner ke columns honge unki to value same hi rahegi soo this
is our base case and we have take the minimum because ek me bhi 0 hua to vo entire square
ka kcuh kam nahi hoga soo minimum lena hoga hame and vo bhi tab jab arr[i][j]==1 ho tab
and then we have to sum all the matrix and return the sum*/



class Solution {
public:
    int countSquares(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
         vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dp[i][0]=arr[i][0];
    }
    for(int j=0;j<m;j++){
        dp[0][j]=arr[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==0){
                dp[i][j]=0;
            }else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    int sum=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           sum=sum+dp[i][j];
        }
    }
    return sum;
    }
};