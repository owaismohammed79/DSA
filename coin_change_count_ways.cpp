class Solution {
  public:
    int fn(vector<int>&coins, int req, int ind, vector<vector<int>>& dp){
        if(req < 0 || ind == coins.size()) return 0;
        if(req == 0) return 1;
        if(dp[ind][req] != -1) return dp[ind][req];
        int left = 0, right = 0;
        if(coins[ind] <= req) {
            left = fn(coins, req-coins[ind], ind, dp);
            right = fn(coins, req, ind+1, dp);
        }
        return dp[ind][req] = left+right;
        
    }
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        sort(coins.begin(), coins.end());
        return fn(coins, sum, 0, dp);
    }
};