class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  
        vector<string> ans;
        sort(folder.begin(),folder.end());
        // for(auto i:folder) cout<<i<<endl;
        string first = folder[0];
        cout<<first;
        ans.push_back(first);
        for(int i=1; i<folder.size(); i++){
            if(folder[i].substr(0,first.size()+1)!=first+"/"){
                ans.push_back(first=folder[i]);
            }
        }
        return ans;
    }
};