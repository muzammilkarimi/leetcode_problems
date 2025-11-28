class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0, ans=0, row=grid.size(), col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                vector<pair<int,int>> dir ={{0,1},{0,-1}, {1,0}, {-1,0}};
                auto [x,y] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nx=x+dir[i].first, ny = y + dir[i].second;
                    if(nx>=0 and nx<row and ny>=0 and ny<col and grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                    }
                }
            }
            ans++;
            if(fresh==0) return ans;
        }
        if(fresh==0) return ans;
        return -1;
        
    }
};