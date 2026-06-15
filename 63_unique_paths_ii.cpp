class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //Just obstacle logic add karni he
        //Base case for loops run karte samay agar obs aaya to kya fill karoge? -1 at that position, what about the next one? I will never be able to reach it, so even if I get one obs the next all would become -1 as we can never reach there. Okay so lets say of the top grid of current one has -1, meaning we cant reach there, then the way to reach it only remains through the left grid, if it is also -1 then the current grid also gets a -1 meaning you can never reach this position too
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(obstacleGrid[0][0]) return 0;
        else dp[0][0]=1;
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] || dp[i-1][0] == 0) dp[i][0] = 0;
            else dp[i][0] = 1;
        }
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] || dp[0][j-1] == 0) dp[0][j] = 0;
            else dp[0][j] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};