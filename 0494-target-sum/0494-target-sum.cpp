class Solution {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,0,0,target);
        return ans;
    }
    void solve(vector<int>&nums, int idx,int sum, int tar){
        if(idx==nums.size()){
            if(sum==tar) ans++;
        }
        else {
            solve(nums,idx+1,sum+nums[idx],tar);
            solve(nums,idx+1,sum-nums[idx],tar);
        }
    }
};