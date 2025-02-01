class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int f = nums[i] % 2, s = nums[i + 1] % 2;
            if(f==s) return false;
        }
        return true;
    }
};