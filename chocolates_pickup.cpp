class Solution {
public:
    int solve(int row, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
        //out of bounds
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -INT_MAX;

        //base case
        if(row == n-1) {
            if(j1 == j2) return grid[row][j1]; //both on same cell
            else return grid[row][j1] + grid[row][j2];
        }

        if(memo[row][j1][j2] != -1) return memo[row][j1][j2];

        int maxChocolates = -1e9;

        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int chocolatesThisCell = 0;
                if(j1 == j2) chocolatesThisCell = grid[row][j1];
                else chocolatesThisCell = grid[row][j1] + grid[row][j2];
                //Now move to next row and compute it
                chocolatesThisCell += solve(row + 1, j1 + dj1, j2 + dj2, n, m, grid, memo);
                maxChocolates = max(maxChocolates, chocolatesThisCell);
            }
        }
        return memo[row][j1][j2] = maxChocolates;
    }

    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return solve(0, 0, m - 1, n, m, grid, memo);
    }
};