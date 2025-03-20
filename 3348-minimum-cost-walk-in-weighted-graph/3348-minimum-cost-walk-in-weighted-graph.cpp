class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj_list, int comp,
             unordered_map<int, int>& nodetocomp, vector<int>& vis) {
        vis[node] = 1;
        nodetocomp[node] = comp;
        for (auto e : adj_list[node]) {
            if (!vis[e])
                dfs(e, adj_list, comp, nodetocomp, vis);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        int e = edges.size();
        vector<vector<int>> adj_list(n, vector<int>(0));
        for (int i = 0; i < e; i++) {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        unordered_map<int, int> nodetocomp;
        int comp = 1;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj_list, comp, nodetocomp, vis);
                comp++;
            }
        }
        vector<int> comptoscore(n,pow(2,31)-1);
        for(int i=0; i<e; i++){
            comptoscore[nodetocomp[edges[i][0]]]=comptoscore[nodetocomp[edges[i][0]]]&edges[i][2];
        }
        vector<int> ans;
        for(int i=0; i<query.size(); i++){
            if(query[i][0]==query[i][1]) ans.push_back(0);
            else if(nodetocomp[query[i][0]]==nodetocomp[query[i][1]]) ans.push_back(comptoscore[nodetocomp[query[i][0]]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};