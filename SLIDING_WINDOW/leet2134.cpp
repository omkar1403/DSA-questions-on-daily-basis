
int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalone=count(nums.begin(),nums.end(),1);  //here we count the number of 1s
        int window=totalone;   // so our window should be of size of total no. of 1s
        if(window==n || window==0){  //if there is no ones all or ones that means no need of swapping
            return 0;
        }
        int current1=0;
        for(int i=0;i<window;i++){
            if(nums[i]==1){  //here we just run loop till windowsize to cover all the ones
               current1++;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
           current1-=nums[i]; //here we just subtract the each current value in the window
           current1+=nums[(i+window)%n]; //here we add the next element in the window
           maxi=max(maxi,current1);  //here we take the maximum number of ones 
        }
       return window-maxi; //and here we just subtract the oness
    }