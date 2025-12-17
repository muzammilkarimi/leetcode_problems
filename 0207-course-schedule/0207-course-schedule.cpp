class Solution {
public:
    bool check(unordered_map<int, vector<int>>& adj, int n,
               vector<int>& indegree) {
        queue<int> q;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v :adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto i : prerequisites) {
            int a = i[0], b = i[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return check(adj, numCourses, indegree);
    }
};