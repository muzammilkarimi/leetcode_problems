class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            priority_queue<pair<int, int>> pq;
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            for (const auto& m : mp) {
                pq.push({m.second, m.first});
            }
            int sum = 0;
            for (int l = 0; l < x && !pq.empty(); l++) {
                auto s = pq.top();
                sum += s.first * s.second;
                pq.pop();
            }
            ans.push_back(sum);
        }

        return ans;
    }
};