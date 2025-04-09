class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (*min_element(nums.begin(), nums.end()) < k)
            return -1;
        int count = 0;
        set<int> st(nums.begin(),nums.end());
        for (int n : st) {
            if (n > k)
                count++;
        }
        return count;
    }
};