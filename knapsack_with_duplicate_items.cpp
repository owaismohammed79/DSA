class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> dp(capacity + 1, 0);

        for(size_t i = 0; i < val.size(); i++) {
            for(int w = wt[i]; w <= capacity; w++) {
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }

        return dp[capacity];
    }
};