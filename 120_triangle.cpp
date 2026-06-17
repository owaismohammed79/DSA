class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = triangle[0][0];
        //What is dp array essentially storing? In a index, it's storing the sum of the 2 ways that will that we can take from the current step 
        for(int i = 1; i < m; i++){
            for(int j = 0; j <= i; j++){
                int val1 = INT_MAX, val2 = INT_MAX;
                if(j != triangle[i-1].size()) val1 = dp[i-1][j] + triangle[i][j];
                if(j > 0) val2 = dp[i-1][j-1] + triangle[i][j];
                dp[i][j] = min(val1, val2);
            }
        }
        auto it = min_element(dp[m-1].begin(), dp[m-1].end());
        return *it;
    }
};