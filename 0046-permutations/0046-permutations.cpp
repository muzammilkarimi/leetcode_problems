class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int> &curr, int idx){
        if(idx == nums.size()-1) ans.push_back(nums);
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i],nums[idx]);
            solve(nums, ans, curr, idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,ans,curr,0);
        return ans;
    }
};