class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int n:nums) sum+=n;
        if(sum<abs(target) or (sum+target)%2!=0) return 0;
        int p = (sum+target)/2;

        vector<int> dp(p+1,0);
        dp[0]=1;
        for(int n:nums){
            for(int i=p; i>=n; i--){
                dp[i]+=dp[i-n];
            }
        }
        return dp[p];
    }
};