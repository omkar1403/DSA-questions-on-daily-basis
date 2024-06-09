/*we have to store the element in the hashmap and check wheather there are more than 1 zeroes
then we have add the sum%k into the map if there is no single element that means the ans should be greater than 1
then we will return the number */



class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
        if(nums.size()<2 && nums[0]!=0){
            return false;
        }
        unordered_map<int, int> mp;
        //-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone may be a multiple as 0-(-1) is not greater than 1
        mp[0]=-1;
        
        int runningSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            runningSum = runningSum%k;
            //check if the runningsum already exists in the hashmap
            if(mp.find(runningSum)!=mp.end())
            {
                //if it exists, then the current location minus the previous location must be greater than1
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
            {
                //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                mp[runningSum]=i;
            }            
        }
        return false;
    }
};