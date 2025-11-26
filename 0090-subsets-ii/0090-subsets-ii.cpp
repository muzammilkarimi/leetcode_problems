class Solution {
public:
    void solve(int idx,set<vector<int>>&s, vector<int>& curr,vector<int> & nums){
        s.insert(curr);
        for(int i=idx; i<nums.size(); i++){
            curr.push_back(nums[i]);
            solve(i+1, s,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n=nums.size();
        vector<int> curr;
        solve(0,s,curr,nums);
        vector<vector<int>> ans;
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
        
    }
};