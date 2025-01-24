class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (r == 0 and c == 0)
            return grid[0][0];
        if (r < 0 or c < 0)
            return INT_MAX;
        if (dp[r][c] != -1)
            return dp[r][c];
        int left = f(r - 1, c, grid, dp);
        int up = f(r, c - 1, grid, dp);
        return dp[r][c] = grid[r][c] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        cin.tie(0);
        ios_base::sync_with_stdio(false);
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return f(row - 1, col - 1, grid, dp);
    }
};