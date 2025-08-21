class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int win=nums[0],count=1;
        if(nums.size()==1) return win;
        for(int i=1; i<nums.size(); i++){
            if(count==0) win=nums[i];
            if(nums[i]==win) count++;
            else count--;
        }
        return win;
        
    }
};