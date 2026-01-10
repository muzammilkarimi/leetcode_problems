class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans =  0, n = nums.size();
        int pref = 1, suff = 1;
        for(int i =0; i<n; i++){
            if(pref==0) pref = 1;
            if(suff == 0) suff = 1;
            pref *= nums[i];
            suff *= nums[n-1-i];
            ans = max(ans, max(pref,suff));
        }
        return ans;
    }
};