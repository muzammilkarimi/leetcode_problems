class Solution {
public:
    bool isValid(int x,int y,int r,int c){
        return (x>=0 and y>=0 and x<r and y<c);
    }
    int minCost(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dp(105,vector<int>(105,1000000));
        dp[0][0]=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first,y=curr.second;
            for(int i=0; i<4; i++){
                int X=x+dir[i].first;
                int Y=y+dir[i].second;
                if(isValid(X,Y,r,c)){
                    if(i+1==grid[x][y] and dp[X][Y]>dp[x][y]){
                        dp[X][Y]=dp[x][y];
                        q.push({X,Y});
                    }
                    else if(dp[x][y]+1<dp[X][Y]){
                        dp[X][Y]=dp[x][y]+1;
                        q.push({X,Y});
                    }
                    
                }
            }
        }
        return dp[r-1][c-1];
        
    }
};