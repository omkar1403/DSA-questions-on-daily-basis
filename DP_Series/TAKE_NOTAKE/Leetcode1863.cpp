/*isme dekho hamne ind less than hone pe sum return ki hai soo
u have to return the total sum Firstly i made a mistake that I was returning nums[ind]^sum
on ind==0 which is wrong because it is already calculating in take part soo u have to just return the sum when u 
are going out of index that's it*/



class Solution {
int func(vector<int>& nums,int ind,int sum){
    if(ind<0){
        return sum;
    }

  
    int notake=func(nums,ind-1,sum);
    int take=func(nums,ind-1,sum^nums[ind]);
    return take+notake;

}

public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return func(nums,n-1,0);
    }
};





//Approach 2

/*isme hamne pahle store kiya hai and then we are calculating the sum by adding all the elements
*/
class Solution {
void solve(vector<int>& arr, vector<vector<int>>& subsets, vector<int> curr_subset, int i =0){
        if(i == arr.size()){
            subsets.push_back(curr_subset);
            return;
        }
        // Include
        curr_subset.push_back(arr[i]);
        solve(arr, subsets,curr_subset, i+1);
        // Backtrack
        curr_subset.pop_back();
        // Exclude
        solve(arr, subsets,curr_subset, i+1);
    }

public:
    int subsetXORSum(vector<int>& arr) {
       vector<vector<int>> subsets;
        vector<int> curr_subset;
        solve(arr,subsets,curr_subset);

        // Step 2:
        int grand_total = 0;
        for(auto i: subsets){
            int curr_total = 0;
            for(auto j: i){
                curr_total =  (curr_total ^ j);
            }
            grand_total += curr_total;
        }
        return grand_total;
    }
};