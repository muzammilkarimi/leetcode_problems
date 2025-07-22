class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curr = 0, ans = 0;
        map<int, int> count;
        int i = 0, j = 0;
        while ( j < nums.size()) {
            if (count.find(nums[j]) == count.end()) {
                count[nums[j]]=1;
                curr += nums[j++];
                ans = max(curr, ans);
            } else {
                count[nums[i]]--;
                curr -= nums[i];
                if (count[nums[i]] == 0) {
                    count.erase(nums[i]);
                }
                i++;
            }
        }
        return ans;
    }
};