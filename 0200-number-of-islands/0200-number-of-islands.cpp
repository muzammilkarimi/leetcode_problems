class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int row = grid.size(), col = grid[0].size();
        grid[i][j] = '0';
        vector<int> xdir = {1, 0, -1, 0};
        vector<int> ydir = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newdiri = i + xdir[k];
            int newdirj = j + ydir[k];
            if (newdiri >= 0 and newdirj >= 0 and newdiri < row and
                newdirj < col and grid[newdiri][newdirj] == '1') {
                dfs(grid, newdiri, newdirj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(),ans=0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};