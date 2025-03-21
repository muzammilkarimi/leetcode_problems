class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingr, vector<string>& supplies) {
        int n=recipes.size();
        vector<string> ans;
        unordered_set<string> supp_set(supplies.begin(),supplies.end());
        unordered_map<string,vector<string>> ingtorec;
        unordered_map<string,int> indegree;
        for(int i=0; i<n; i++){
            indegree[recipes[i]]=ingr[i].size();
            for(auto ing:ingr[i]){
                ingtorec[ing].push_back(recipes[i]);
            }
        }
        queue<string> q;
        for(auto i:supplies) q.push(i);
        while(!q.empty()){
            string item=q.front();
            q.pop();

            if(find(recipes.begin(),recipes.end(),item)!=recipes.end()) ans.push_back(item);
            for(auto &rec:ingtorec[item]){
                indegree[rec]--;
                if(indegree[rec]==0) q.push(rec);
            }
        }
        return ans;

    }
};