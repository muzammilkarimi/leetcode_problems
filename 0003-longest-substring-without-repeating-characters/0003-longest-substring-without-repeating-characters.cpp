class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0,last=0;
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i])) last = max(last,mp[s[i]]+1);
            mp[s[i]]=i;
            ans=max(ans,i-last+1);
        }
        return ans;
        
    }
};