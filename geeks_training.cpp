class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for(int act = 0; act < 3; act++) dp[0][act] = mat[0][act];
        for(int day = 1; day < n; day++) {
            for(int act = 0; act < 3; act++) {
                dp[day][act] = mat[day][act] + max(dp[day-1][(act+1)%3], dp[day-1][(act+2)%3]);
            }
        }
        
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};