class Solution {
public:
    bool isvalid(int row, int col, int r, int c) {
        return (row >= 0 and row < r and col >= 0 and col < c);
    }
    int dfs(int row, int col, int id, vector<vector<int>>& grid,
            vector<vector<int>>& vis, int r, int c) {
        if (!isvalid(row, col, r, c) or vis[row][col] != -1 or
            grid[row][col] == 0)
            return 0;
        vis[row][col] = id;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int sum = 1;
        for (int i = 0; i < 4; i++) {
            int x = row + dir[i].first, y = col + dir[i].second;
            sum += dfs(x, y, id, grid, vis, r, c);
            // cout<<sum<<" "<<x<<y<<endl;
        }
        // vis[row][col]=0;
        // cout<<"final sum"<<sum<<endl;
        return sum;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, -1));
        unordered_map<int, int> countisland;
        int r = 0, maxsize = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 and vis[i][j] == -1) {
                    int size = dfs(i, j, r, grid, vis, row, col);
                    countisland[r] = size;
                    maxsize = max(maxsize, size);
                    r++;
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                unordered_set<int> adj;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dir[k].first;
                        int y = j + dir[k].second;
                        if (isvalid(x, y, row, col) and vis[x][y] != -1) {
                            adj.insert(vis[x][y]);
                        }
                    }
                    int total = 1;
                    for (auto & i : adj)
                        total += countisland[i];
                    maxsize = max(maxsize, total);
                }
            }
        }
        return maxsize == 0 ? row * col : maxsize;
    }
};