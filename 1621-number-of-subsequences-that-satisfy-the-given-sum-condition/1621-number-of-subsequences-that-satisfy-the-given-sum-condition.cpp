class Solution {
public:
long long power(long long base, long long exp, int mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (r >= l) {
            if (nums[r] + nums[l] > target) {
                r--;
            } else {
                const int MOD = 1e9 + 7;
                ans = (ans + power(2, r - l, MOD)) % MOD;
                l++;
            }
        }
        return ans;
    }
};