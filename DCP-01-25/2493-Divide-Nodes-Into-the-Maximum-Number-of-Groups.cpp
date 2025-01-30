class Solution {
public:
    void findconnectedcomponents(int i, vector<vector<int>> &adj,unordered_set<int> &connectedcompts){
        connectedcompts.insert(i);
        for(int ngbr:adj[i]){
            if(connectedcompts.count(ngbr)==0){
                findconnectedcomponents(ngbr,adj,connectedcompts);
            }
        }
    }
    int findmaxdepth(int start,vector<vector<int>> &adj,unordered_set<int> &connectedcompts,vector<int> &visited){
        for(int node:connectedcompts) visited[node]=-1;
        queue<int> q;
        int depth=1;
        q.push(start);
        visited[start]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int ngbr:adj[curr]){
                if(visited[ngbr]==-1){
                    visited[ngbr]=visited[curr]+1;
                    depth = max(depth,visited[ngbr]);
                    q.push(ngbr);
                }
                else if(abs(visited[ngbr]-visited[curr])!=1) return -1;
            }
        }
        return depth;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // edges into adjancy list
        vector<vector<int>> adj(n+1);
        vector<int> visited(n+1,-1);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int maxgroups=0;
        unordered_set<int> connectedcompts;
        for(int i=1; i<=n; i++){
            if(visited[i]!=-1) continue;
            connectedcompts.clear();
            findconnectedcomponents(i,adj,connectedcompts);
            int maxdepth=-1;
            for(int node:connectedcompts){
                maxdepth=max(maxdepth,findmaxdepth(node,adj,connectedcompts,visited));
            }
            if(maxdepth==-1) return -1;
            maxgroups+=maxdepth;
        }
        return maxgroups;

    }
};