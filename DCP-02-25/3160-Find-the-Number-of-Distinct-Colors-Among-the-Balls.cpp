class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans;
        unordered_map<int,int> balls,color;
        int dis=0;
        for(auto &q:queries){
            int pos=q[0], col=q[1];
            if(balls.count(pos))
                if(--color[balls[pos]]==0) dis--;
            balls[pos]=col;
            if(++color[col]==1) dis++;
            ans.push_back(dis);
        }
        return ans;

        
    }
};