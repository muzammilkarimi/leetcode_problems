class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]) l = m+1;
            else r=m;
        }
        int pivot = l;
        int temp = binarysearch(0,pivot-1,target,nums);
        if(temp!=-1) return temp;
        return binarysearch(pivot,nums.size()-1,target,nums);
    }
    int binarysearch(int l,int r, int target,vector<int>& nums){
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
        return -1;
    }
};
