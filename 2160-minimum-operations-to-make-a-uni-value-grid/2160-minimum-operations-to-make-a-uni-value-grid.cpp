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
        int l=onedim.size();
        nth_element(onedim.begin(),onedim.begin()+l/2,onedim.end());
        int mid=onedim[l/2];
        cout<<mid;
        int ans=0;
        for(int i:onedim){
            ans+=abs(mid-i)/x;
        }

        return ans;
        
    }
};