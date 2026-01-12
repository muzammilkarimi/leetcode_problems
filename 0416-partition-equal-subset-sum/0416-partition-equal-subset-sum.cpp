class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num:nums) sum+=num;
        if(sum%2!=0) return false;
        vector<int> dp(sum/2+1,false);
        dp[0]=true;
        for(int n:nums){
            for(int i=sum/2; i>=n; i--){
                dp[i]=dp[i] or dp[i-n];
                if(dp[sum/2]) return true;
            }
        }
        return dp[sum/2];
    }
};