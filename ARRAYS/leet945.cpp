/*V.V.IMP. we have to make the unique array by increament so first we will sort the elements
hamne kya kiya ki agar koi element ye less than or equal to hoga to we will count the moves
else we will increament the ans as nums[i] and agar 
hame similar elements mil gaye then we will increament the ans and then take absolute of the given 
count.*/



int minIncrementForUnique(vector<int>& nums) {
       int count=0;
       sort(nums.begin(),nums.end());
       int ans1=nums[0];
     
       for(int i=1;i<nums.size();i++){
           if(nums[i-1]>=nums[i]){

            ++ans1;
            count=count+abs(ans1-nums[i]);
            nums[i]=ans1;

           }else{
            ans1=nums[i];
           }
       }
       return count;

       
    }