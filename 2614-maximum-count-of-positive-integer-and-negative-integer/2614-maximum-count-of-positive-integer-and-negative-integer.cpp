class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0,neg=0;
        auto n1=lower_bound(nums.begin(),nums.end(),0);
        auto n2=upper_bound(nums.begin(),nums.end(),0);
        pos=nums.end()-n2;
        neg=n1-nums.begin();
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]>0) pos++;
        //     else if(nums[i]<0) neg++;
        // }
        return max(pos,neg);
        
    }
};