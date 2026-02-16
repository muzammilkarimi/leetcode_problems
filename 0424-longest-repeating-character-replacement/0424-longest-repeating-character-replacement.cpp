class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int r=0,l=0,ans=0,maxf=0;
        while(r<s.size()){
            mp[s[r]]++;
            maxf=max(maxf,mp[s[r]]);
            while((r-l+1)-maxf>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};