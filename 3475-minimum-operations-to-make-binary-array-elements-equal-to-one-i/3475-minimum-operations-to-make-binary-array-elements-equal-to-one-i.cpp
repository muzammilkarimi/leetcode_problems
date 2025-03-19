class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        for(int i=0; i+2<nums.size(); i++){
            if(nums[i]==0){
                nums[i]=nums[i]?0:1;
                nums[i+1]=nums[i+1]?0:1;
                nums[i+2]=nums[i+2]?0:1;
                count++;
            }
        }
        for(int i:nums) if(i==0) return -1;
        return count;
        
    }
};