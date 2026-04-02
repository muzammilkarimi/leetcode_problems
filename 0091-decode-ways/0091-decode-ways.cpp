class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp (s.size(),-1);
        return solve(s,0,dp);
    }
    int solve(string s, int i, vector<int>&dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int res = solve(s,i+1,dp);
        if(i<s.size()-1){
            if(s[i]=='1' or (s[i]=='2' and s[i+1]<'7')){
                res+=solve(s,i+2,dp);
            }
        }
        return dp[i]=res;
    }
};