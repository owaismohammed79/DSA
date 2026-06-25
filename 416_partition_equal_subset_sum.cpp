class Solution {
public:
    bool fn(int pos, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(pos >= nums.size()) return false;
        if(dp[pos][target] != -1) return dp[pos][target];
        
        bool x = fn(pos + 1, target, nums, dp);
        
        bool y = false;
        if(nums[pos] <= target) y = fn(pos + 1, target - nums[pos], nums, dp);
        return dp[pos][target] = (y || x);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        //if sum is odd, we cant split at all        
        if(sum % 2 != 0) return false;
        int target = sum/2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return fn(0, target, nums, dp);
    }
};