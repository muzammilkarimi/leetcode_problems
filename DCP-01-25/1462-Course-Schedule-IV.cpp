class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
            in[pre[1]]++;
        }
        // starting point
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in[i]==0) q.push(i);
        }

        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()){
            int par = q.front();
            q.pop();
            for(auto child: adj[par]){
                mp[child].insert(par); // direct son
                for(auto grand:mp[par]){
                    mp[child].insert(grand); // indirect son
                }
                if(--in[child]==0) q.push(child);
            }

        }
        vector<bool> ans;
        for(auto q:queries) ans.push_back(mp[q[1]].count(q[0]));
        return ans;
    }
};