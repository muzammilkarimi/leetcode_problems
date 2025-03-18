class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0;
        int ans=0,curr_sum=0,curr_xor=0;
        while(r<n){
            curr_sum+=nums[r];
            curr_xor^=nums[r];
            while(curr_sum!=curr_xor){
                curr_sum-=nums[l];
                curr_xor^=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};