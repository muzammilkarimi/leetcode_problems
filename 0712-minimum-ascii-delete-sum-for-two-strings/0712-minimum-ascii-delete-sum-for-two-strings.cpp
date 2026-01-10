class Solution {
public:
    int s1, s2;
    int solve(int i, int j, string& str1, string& str2,
              vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i >= s1 and j >= s2)
            return 0;
        if (i >= s1) {
            return str2[j] + solve(i, j + 1, str1, str2, dp);
        }
        if (j >= s2)
            return str1[i] + solve(i + 1, j, str1, str2, dp);
        if (str1[i] == str2[j])
            return dp[i][j] = solve(i + 1, j + 1, str1, str2, dp);
        int del_s1 = str1[i] + solve(i + 1, j, str1, str2, dp);
        int del_s2 = str2[j] + solve(i, j + 1, str1, str2, dp);

        return dp[i][j] = min(del_s1, del_s2);
    }
    int minimumDeleteSum(string str1, string str2) {
        s1 = str1.size();
        s2 = str2.size();

        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0, 0, str1, str2, dp);
    }
};