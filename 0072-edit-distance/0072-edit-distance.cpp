class Solution {
public:
    int solve(int s1, int s2, string& word1, string& word2,vector<vector<int>>& dp) {
        // base case
        if (s1 < 0)
            return s2 + 1;
        if (s2 < 0)
            return s1 + 1;
        if(dp[s1][s2]!=-1) return dp[s1][s2];
        if (word1[s1] == word2[s2]) {
            return dp[s1][s2] = solve(s1 - 1, s2 - 1, word1, word2,dp);
        }
        int ins = solve(s1, s2 - 1, word1, word2,dp);
        int del = solve(s1 - 1, s2, word1, word2,dp);
        int rep = solve(s1 - 1, s2 - 1, word1, word2,dp);
        return dp[s1][s2] = 1 + min(ins, min(del, rep));
    }
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1, vector<int>(s2,-1));
        return solve(s1 - 1, s2 - 1, word1, word2,dp);
    }
};