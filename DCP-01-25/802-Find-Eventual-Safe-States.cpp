class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited,
             vector<int>& pathvis, vector<int>& check) {
        visited[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for (auto i : graph[node]) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, pathvis, check)) return true;
            } else if (pathvis[i]) return true;
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int node = graph.size();
        vector<int> visited(node, 0), pathvis(node, 0), check(node, 0);
        for (int n = 0; n < node; n++) {
            if (!visited[n])
                dfs(n, graph, visited, pathvis, check);
        }
        vector<int> safenodes;
        for (int i = 0; i < node; i++) {
            if (check[i] == 1)
                safenodes.push_back(i);
        }
        return safenodes;
    }
};