class Solution {
  public:
    bool fn(vector<int>& arr, int pos, int target, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(pos >= arr.size()) return false;
        if(dp[pos][target] != -1) return dp[pos][target];
        

        if(arr[pos] > target) return dp[pos][target] = fn(arr, pos + 1, target, dp);
        
        bool include = fn(arr, pos + 1, target - arr[pos], dp);
        
        bool exclude = fn(arr, pos + 1, target, dp);
        
        return dp[pos][target] = (include || exclude);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return fn(arr, 0, sum, dp);
    }
};