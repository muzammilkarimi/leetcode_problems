class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp) {
        // base case
        if (row == 0 and col == 0)
            return 1;
        if (row < 0 or col < 0)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = solve(row - 1, col, dp) + solve(row, col - 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 and j==0) dp[i][j]=1;
                else{
                    int left=0,up=0;
                    if(i>0) left=dp[i-1][j];
                    if(j>0) up=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};