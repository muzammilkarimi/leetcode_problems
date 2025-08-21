class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,l=0;
        set<int> unique;
        for(int i=0; i<s.size(); i++)
        {
            while(unique.find(s[i])!=unique.end()){
               unique.erase(s[l]);
               l++;
                
            }
            unique.insert(s[i]);
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};