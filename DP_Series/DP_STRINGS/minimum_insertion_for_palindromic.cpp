/*pahle iska LCS nikala phir isko compare karne ke liye ek string banayi jo ki uske reverse thi then 
  hamne ussse longest commmon subsequence find kiya soo hence we get the palindromic sequence and now 
  jitne bhi sequence aayenge unko (n-unki length) karne pe we will get minimum insertion*/

class Solution {

int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    } 
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

public:
    int minInsertions(string s) {
        string a="";
        for(int i=s.size()-1;i>=0;i--){
            a.push_back(s[i]);
        }
        int n=s.length()-1;
       
       
        int k=lcs(s,a);
        return l-k;

    }
};