class Solution {
public:
    /*
    The fault here was thinking that I had to go backwards and then re use the dp
    it's actually going forward, it completes the recursion, stores everything and then
    reuses it in the next path
    */
    int dontRob(vector<int>& nums, int ind, vector<int>& dp) {
        if(ind >= nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int num1 = nums[ind] + dontRob(nums, ind + 2, dp); //rob
        int num2 = dontRob(nums, ind + 1, dp); //skip
        return dp[ind] = max(num1, num2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dontRob(nums, 0, dp);
    }
};