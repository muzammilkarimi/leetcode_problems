class Solution {
public:
    int M = 1e9 + 7;
    int solve(int n, int x, vector<vector<int>>& dp, int p) {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (p > n) return 0;
        if (dp[n][p] != -1)
            return dp[n][p];
        long long pow_val = pow(p, x);
        if (pow_val > n)
            return dp[n][p] = 0;
        int take = solve(n - pow_val, x, dp, p + 1);
        int not_take = solve(n, x, dp, p + 1);
        return dp[n][p] = (take + not_take) % M;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, x, dp, 1);
    }
};