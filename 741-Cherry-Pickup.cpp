class Solution {
public:
    int solve(int r1,int c1, int c2, int n, vector<vector<int>> & grid, vector<vector<vector<int>>> &dp){
        int r2=r1+c1-c2;
        if(r1>=n or c1>=n or r2>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1 ) return -1e8;
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        if(r1==n-1 and c1==n-1) return grid[r1][c1];
        int ans=grid[r1][c1];
        if(c1!=c2) ans+=grid[r2][c2];
        int temp = max(solve(r1,c1+1,c2+1,n,grid,dp),solve(r1+1,c1,c2,n,grid,dp));
        temp = max(temp,solve(r1+1,c1,c2+1,n,grid,dp));
        temp = max(temp,solve(r1,c1+1,c2,n,grid,dp));
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solve(0,0,0,n,grid,dp));

        

    }
};


// right = i,j+1   down = i+1,j
// left = i,j-1    up  = i-1,j