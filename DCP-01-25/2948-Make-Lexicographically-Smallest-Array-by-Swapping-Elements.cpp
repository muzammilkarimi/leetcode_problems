class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        unordered_map<int, queue<int>> level;
        unordered_map<int, int> mp;

        int curr= 0;
        level[curr].push(copy[0]);
        mp[copy[0]] = curr;
        for(int i=1; i<copy.size(); i++) {
            int last = level[curr].back();
            if(copy[i]-last <= limit)
                level[curr].push(copy[i]);
            else {
                ++curr;
                level[curr].push(copy[i]);
            }
            mp[copy[i]] = curr;
        }
        vector<int> ans;
        for(int i=0; i<nums.size();i++) {
            int lvl = mp[nums[i]];
            ans.push_back(level[lvl].front());
            level[lvl].pop();
        }
        return ans;
    }
};