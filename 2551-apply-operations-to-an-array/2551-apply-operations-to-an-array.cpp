class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == 0) {
                for (int j = i+1; j < n; j++) {
                    // j=1 n=2 
                    if (nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};