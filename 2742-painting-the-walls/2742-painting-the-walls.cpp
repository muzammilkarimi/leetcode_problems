class Solution {
public:
    int solve(int i, int walls, vector<int>& cost, vector<int>& time,vector<vector<int>> &dp){
        if(walls<=0) return 0;
        if(i<0) return 1e9;
        if(dp[i][walls]!=-1) return dp[i][walls];
        return dp[i][walls] =  min(solve(i-1,walls,cost,time,dp),cost[i]+solve(i-1,walls-time[i]-1,cost,time,dp));
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,cost,time,dp);
    }
};