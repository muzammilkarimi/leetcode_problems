class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string ans="";
        for(int i=0,j=0; i<strs[0].length(),j<strs[n-1].length(); i++,j++){
            if(strs[0][i]!=strs[n-1][i]) break;
            else ans+=strs[0][i];
        }
        return ans;
        // int ans=strs[0].length();
        // for(int i=1; i<n; i++){
        //     int curr=0;
        //     while(curr<strs[i].length() and strs[i][curr] == strs[0][curr]) curr++;
        //     ans=min(ans,curr);
        // }
        // return strs[0].substr(0,ans);
        
    }
};