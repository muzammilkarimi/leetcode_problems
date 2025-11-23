class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int n:nums){
            int i = abs(n);
            if(nums[i]<0) return i;
            nums[i]=-nums[i];
        }
        return 0;
        
    }
};