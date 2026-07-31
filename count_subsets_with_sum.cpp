class Solution {
  public:
    int fn(vector<int>& arr, int ind, int target, vector<vector<int>>& dp){
        if(target < 0) return 0;
        if(ind == arr.size()) {
            if(target) return 0;
            return 1;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int l = fn(arr, ind+1, target-arr[ind], dp);
        int r = fn(arr, ind+1, target, dp);
        return dp[ind][target] = l+r;
        
    }
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
        return fn(arr, 0, target, dp);
    }
};