class Solution {
public:
    void dfs(int node,vector<int>&comp,vector<vector<int>>&adj_list,vector<bool>&vis){
        vis[node]=true;
        comp.push_back(node);
        for(int n:adj_list[node]){
            if(!vis[n]) dfs(n,comp,adj_list,vis);
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
                vector<int> comp;
                dfs(i,comp,adj_list,vis);
                bool iscompl=true;
                for(auto &it:comp){
                    if(adj_list[it].size()!=comp.size() - 1){
                        iscompl=false;
                        break;
                    }
                }
                if(iscompl) ans++;
                
            }
        }
        return ans;
    }
};