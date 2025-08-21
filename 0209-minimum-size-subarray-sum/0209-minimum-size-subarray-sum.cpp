class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int i=0,j=0;
        int ans=INT_MAX,sum=0;
        while(j<nums.size()){
            sum+=nums[j++];
            while(sum>=tar){
                ans=min(ans,j-i);
                sum-=nums[i];
                i++;
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
        
    }
};