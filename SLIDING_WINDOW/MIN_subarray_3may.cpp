


#include <vector>
#include<climits>

int minSubArrayLen(vector<int>& arr, int target, int n) {
     
int window=0,left=0,ans=INT_MAX;
for(int i=0;i<n;i++){
  window+=arr[i];
  while(window>target){
      ans=min(ans,i-left+1);
      window=window-arr[left++];
  }

}
return ans==INT_MAX?0:ans;
  }

  
