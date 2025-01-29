class Solution {
public:
    bool isvalid(int u,int v, int par,unordered_map<int,vector<int>> &adj){
        if(u==v) return true;
        for(auto &nxt:adj[u]){
            if(par==nxt) continue;
            if(isvalid(nxt,v,u,adj)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        for(auto& edge:edges){
            int u=edge[0],v=edge[1];
            if(isvalid(u,v,0,adj)) return edge;
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return {};
    }
};