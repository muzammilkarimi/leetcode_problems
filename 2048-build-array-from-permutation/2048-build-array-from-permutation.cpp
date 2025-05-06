class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int num:nums){
            ans.push_back(nums[num]);
        }
        return ans;
    }
};