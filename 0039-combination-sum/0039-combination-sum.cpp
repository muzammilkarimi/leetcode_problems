class Solution {
public:
    void solve(int idx, vector<int>& nums, int target,vector<int> & curr, vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            if(target>=nums[i]){
                curr.push_back(nums[i]);
                solve(i,nums,target-nums[i],curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,target,curr,ans);
        return ans;
        
    }
};