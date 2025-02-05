class Solution {
public:
    int solve(int roboi,int robo1j,int robo2j,int row,int col, vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(robo1j<0 or robo1j>=col or robo2j<0 or robo2j>=col) return -1e8;
        if(roboi==row-1){
            if(robo1j==robo2j) return grid[roboi][robo1j];
            else return grid[roboi][robo1j] + grid[roboi][robo2j];
        }
        if(dp[roboi][robo1j][robo2j]!=-1) return dp[roboi][robo1j][robo2j];

        // explore all the paths of both the robos
        int maxi=-1e8;
        for(int dir1=-1; dir1<=1; dir1++){
            for(int dir2=-1; dir2<=1; dir2++){
                int value=0;
                if(robo1j==robo2j) value=grid[roboi][robo1j];
                else value=grid[roboi][robo1j]+grid[roboi][robo2j];

                value+=solve(roboi+1,robo1j+dir1,robo2j+dir2,row,col,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[roboi][robo1j][robo2j]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col, vector<int>(col,-1)));
        return solve(0,0,col-1,row,col,grid,dp);

        
    }
};