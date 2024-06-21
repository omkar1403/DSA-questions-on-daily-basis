class Solution {
     bool canWePlace(const vector<int>& arr, int mid, int balls) {
        int countBalls = 1;
        int last = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[last] >= mid) {//here we have to maintain the maximum or equal to distance from the mid
                countBalls++; //if we it is then place the ball
                last = i;   //last equal to i kar denge
            }
            if (countBalls >= balls) {
                return true; //if ye sab karke if we calculated balls are higher then we will return the true
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
      sort(position.begin(), position.end());
        int low = 1;
        int high = position[position.size()-1];//here we took the highest element
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;//here we find the mid
            if (canWePlace(position, mid, m)) {  //if it is true then 
                ans = mid; //ans equals to mid kar denge 
                low = mid + 1;//and we simply try for some better distance 
            } else {
                high = mid - 1;//else we will decrease the high to mid
            }
        }
        return ans;//and return the ans
    }
};