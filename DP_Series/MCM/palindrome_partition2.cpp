/*PALINDROME PARTITION 2 
yaha ham loop run karenge in which we run a loop from i to j and hamara base case hai (i>j) return 0
if it is palindrome then we add a cost 1+remaining partition and maintain a mini and then maintain a dp
and return it*/




bool ispalindrome(string s,long long i,long long j){
  
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int func(long long ind,string &s,vector<long long>&dp){
    if(ind==s.length()){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
   long long mini=1e9;
    for(long long i=ind;i<s.length();i++){
        if(ispalindrome(s,ind,i)){
            long long cost=1+func(i+1,s,dp);
            mini=min(mini,cost);
        }
    }
    return dp[ind]=mini;
}
int palindromePartitioning(string str)
{
    int n=str.length();
    vector<long long>dp(n,-1);
    return func(0,str,dp)-1;
}