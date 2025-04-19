class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            auto lw_index = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto up_index = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-1;
            ans+=up_index-lw_index+1;
        }
        return ans;


    }
};
//  0 1 4 4 5 7  l=3 u=6
// 1 2 5 7 9 
// l=11,  u=11 