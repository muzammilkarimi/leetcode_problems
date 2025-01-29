class Solution {
public:
    bool isvalid(int row, int col, int r, int c) {
        return (row >= 0 and row < r and col >= 0 and col < c);
    }
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis, int r, int c) {
        // base case
        vis[row][col] = 1;
        vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        int sum=0;
        for (int i = 0; i < 4; i++) {
            int x = row+dir[i].first, y = col+dir[i].second;
            if (isvalid(x, y, r, c) and !vis[x][y] and grid[x][y]>0) {
                        sum += dfs(x, y, grid, vis, r, c);
            }
        }
        return grid[row][col]+sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0 and !vis[i][j]) {
                    ans=max(ans,dfs(i,j,grid,vis,row,col));
                }
            }
        }
        return ans;
    }
};