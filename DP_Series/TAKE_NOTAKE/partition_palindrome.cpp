/*isme hamne sirf loop lagake add kiya hai*/



class Solution {
bool palindrome(string s,int l,int r){
 while (l <= r) {
if (s[l++] != s[r--]) {
return false;
}
}
return true;
}

void solve(string s,vector<vector<string>>&output,vector<string>ans,int n,int ind){
if(ind==n){
 output.push_back(ans);
return ;
}else{
for(int i=ind;i<s.length();i++){
 if(palindrome(s,ind,i)){
 ans.push_back(s.substr(ind,i-ind+1));
 solve(s,output,ans,n,i+1);
 ans.pop_back();                     
  }
}
}
}

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>output;
        vector<string>ans;
        int n=s.length();
        int ind=0;
        solve(s,output,ans,n,ind);
        return output;
    }
};