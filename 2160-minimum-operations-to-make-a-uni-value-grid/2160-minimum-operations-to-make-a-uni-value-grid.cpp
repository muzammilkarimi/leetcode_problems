class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row=grid.size(),col=grid[0].size();
        vector<int> onedim;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]%x!=grid[0][0]%x) return -1;
                onedim.push_back(grid[i][j]);
            }
        }
        sort(onedim.begin(),onedim.end());
        int l=onedim.size();
        int mid=onedim[l/2];
        cout<<mid;
        int ans=0;
        for(int i:onedim){
            ans+=abs(mid-i)/x;
        }

        return ans;
        
    }
};