/*here we just have to add the mod in the map and if mod is negative then we have ton store the 
mod+k in the hashmap. and we have to add the numbers accordingly in each iteration. and maintain the count
and we have to add the counter according to the map.*/



/*APPROACH 1*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0){
        return 0;
        }
        int sum=0;
        map<int,int>mpp;
        mpp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
        sum=sum+nums[i];
        
        int ans=sum%k;
     
        if(ans<0){
          ans+=k;
          }
        
        if(mpp.find(ans)!=mpp.end()){
           count=count+mpp[ans];
           }
        mpp[ans]++;
        
        }
        return count;
    }
};






/*approach2*/

  int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;