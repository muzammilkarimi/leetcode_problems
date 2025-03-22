class Solution {
public:
    void dfs(int node,int&ver,int&edg,vector<vector<int>>&adj_list,vector<bool>&vis){
        vis[node]=true;
        ver++;
        for(int n:adj_list[node]){
            edg++;
            if(!vis[n]) dfs(n,ver,edg,adj_list,vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        int ans = 0;
        for (auto &e:edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n,0);
        int nodeincomp=1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int ver=0,edg=0;
                dfs(i,ver,edg,adj_list,vis);
                if(edg==ver*(ver-1)) ans++;
                
            }
        }
        return ans;
    }
};