/*please refer the video   https://www.youtube.com/watch?v=x4cRwVEFwHc    here in this we took dp array in another format and 
we have added extra elements 0 and n then we solve for the elements jo ki 0 aur n ke bich me the soo the loop becomes l+1 to r-1 
an then we got the answer */



class Solution {
    int dp[103][103];
    int solve(vector<int>& cuts,int l,int r){
        if(r-l<2){
            return 0;
        }
        int result=INT_MAX;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        for(int i=l+1;i<=r-1;i++){
            int cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
            result=min(result,cost);
        }
        return dp[l][r]=result;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return solve(cuts,0,cuts.size()-1);
    }
};