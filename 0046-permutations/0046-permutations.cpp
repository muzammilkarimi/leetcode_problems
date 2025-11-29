class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int> &curr, vector<int>& freq){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                curr.push_back(nums[i]);
                freq[i]=1;
                solve(nums,ans,curr,freq);
                freq[i]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> freq(nums.size(),0);
        solve(nums,ans,curr,freq);
        return ans;
    }
};