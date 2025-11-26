class Solution {
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx) {
        if (target <= 0) {
            if (target == 0)
                ans.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target >= candidates[i]) {
                curr.push_back(candidates[i]);
                solve(candidates, target - candidates[i], curr, i);
                curr.pop_back();
            } else 
                break;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, curr, 0);
        return ans;
    }
};