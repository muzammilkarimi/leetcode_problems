class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        if(nums.size()==2) return min(nums[0],nums[1]);
        while(low<=high){
            if(nums[low]<=nums[high]) return nums[low];
            else{
                int mid = low+(high-low)/2;
                if(nums[mid]<nums[mid+1] and nums[mid]<nums[mid-1]) return nums[mid];
                else if(nums[high]<nums[mid]) low = mid+1;
                else high = mid-1;
            }
        }
        return nums[0];
    }
};