class Solution {
public:
    int numRescueBoats(vector<int>&a, int l) {
       sort(a.begin(),a.end());
       int i=0;
       int j=a.size()-1;
       int ans=0;
       int sum=0;
       while(i<=j){
        if(a[i]+a[j]<=l){
            i++;
            j--;
        }else{
            j--;
        }
        ans++;
       }
 
       return ans;
    }
};