/*isme hamne first ek loop run kiya from 1 to n-1 and we will take it as (i,k) and (k+1,j)
so steps we require are arr[i-1]*arr[k]*arr[j] as we have seen that loop is from k=i and k<j
because of arr[i-1] and we have to calculate func(k+1,j) 
*/





class Solution{
    
    int func(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mini=1e9;
        
        for(int k=i;k<j;k++){
            int step=arr[i-1]*arr[k]*arr[j]+func(i,k,arr,dp)+func(k+1,j,arr,dp);
            mini=min(mini,step);
            
        }
        return dp[i][j]=mini;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
       vector<vector<int>>dp(N,vector<int>(N,-1));
       return func(1,N-1,arr,dp);
    }
};


//Tabulation approach 

 int dp[N][N];
for(int i=1;i<N;i++){
   dp[i][i]=0;
}
for(int i=N-1;i>=1;i--){
   for(int j=i+1;j<N;j++){
      int mini=1e9;
      for(int k=i;k<j;k++){
         int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
         mini=min(mini,steps);
      }
      dp[i][j]=mini;
   }
}
return dp[1][N-1];