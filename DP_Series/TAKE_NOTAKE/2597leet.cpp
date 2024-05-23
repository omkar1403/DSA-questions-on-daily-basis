/*isme hamm pahle check karenge ki koi element to nahi hai whose sum is equal to  absolute
then ham hoga to continue karenge else ham cur me push karke count increament karenge and then ham pop bhi karneg
soo  that vo loop chalta rahe aur elements add hote rahe and return the count*/



class Solution {
 private:
    int helper(vector<int>& nums, int k, vector<int>& cur, int start) {
        int cnt = 0;
        for (int i = start; i < nums.size(); ++i) {
            if (!test(cur, nums[i], k))
                continue;
            cur.push_back(nums[i]);
            cnt++;
            cnt += helper(nums, k, cur, i + 1);
            cur.pop_back();
        }
        return cnt;
    }
    bool test(vector<int>& cur, int num, int k) {
        for (auto &c : cur)
            if (abs(num - c) == k)
                return false;
        return true;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
       vector<int> cur;
        return helper(nums, k, cur, 0);
    }
}