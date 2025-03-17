class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        if(n==2) return {{1},{1,1}};
        vector<vector<int>> ans(n);
        ans[0]={1};
        ans[1]={1,1};
        int r=2;
        while(r<n){
            ans[r].push_back(1);
            for(int i=0;i<ans[r-1].size()-1; i++){
                ans[r].push_back(ans[r-1][i]+ans[r-1][i+1]);
            }
            ans[r].push_back(1);
            r++;
        }
        return ans;
    }
};