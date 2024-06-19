



class Solution {
   
public:

   bool helper(long long int &mid,vector<int>& bloomDay, int &m, int &k){
        int n = bloomDay.size();
        int bouq = 0;
        int total=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){ //jo bhi day hoga, here we consider maximum ele in array if it is less than we just add 
            total++;    //here we will add
            }
            else{
             total = 0; //else we will make the total=0
            }
            if(total>=k) //V.V.IMP Step:-   here we will check if total is greater or not
            {
                bouq++; //if yes then we will make bouqet
                total = 0;  //and we will make this again 0
            }
        }
    
        return (bouq >=m); //return if it is greater than or equal to bouq
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        
     if(bloomDay.size() < (long long)m*k) return -1; //garden has flowers less than required
        long long int left = 1;
        long long int right = *max_element(bloomDay.begin(), bloomDay.end());//IMP:- that is how we find maximum element in array
       
        while(left<right){
            long long int mid = (left+right)/2; 
            if(helper(mid,bloomDay,m,k)){  //and we compare the mid 
                right = mid; //if it is then highest element we decrease to mid because WE WANT TO FIND THE MINIMUM element
                

            }
            else{
                left = mid+1; //if it can not make bouqet then we will move to greater element to make the bouqet
            }
        }
        return left;//return the ans
    }
};