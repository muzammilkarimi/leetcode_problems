class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size(),col=obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0 and j==0) dp[i][j]=1;
                else{
                    int left=0,up=0;
                    if(i>0) left=dp[i-1][j];
                    if(j>0) up=dp[i][j-1];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[row-1][col-1];
    }
};