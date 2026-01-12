class Solution {
public:
    int solve(int r , int c , vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r==0 and c==0) return grid[0][0];
        if(r<0 or c<0) return INT_MAX;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c] = grid[r][c]+min(solve(r-1,c,grid,dp),solve(r,c-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));

        return solve(row-1,col-1, grid,dp);
    }
};