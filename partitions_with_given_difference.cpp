class Solution {
  public:
    int generateSubsets(vector<int>& arr, int ind, int target, vector<vector<int>>& dp) {
        if (target < 0) return 0;
        if(ind == arr.size()) {
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int left = generateSubsets(arr, ind+1, target, dp);
        int right = generateSubsets(arr, ind+1, target - arr[ind], dp);
        return dp[ind][target] = left+right;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(diff > total || (total+diff)%2) return 0;
        int target = (total+diff)/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return generateSubsets(arr, 0, target, dp);
    }
};