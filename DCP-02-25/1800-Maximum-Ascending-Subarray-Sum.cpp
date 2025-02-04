class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0,sum=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                ans=max(sum,ans);
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return max(sum,ans);
        
    }
};