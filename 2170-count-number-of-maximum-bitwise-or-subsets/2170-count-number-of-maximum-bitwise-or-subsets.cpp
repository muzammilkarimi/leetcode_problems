class Solution {
public:
    
    int solve(vector<int> & nums, int maxor,int index,int curror){
        if(index==nums.size()) return curror==maxor?1:0;
        if(curror==maxor) return 1<<(nums.size()-index);
        int take = solve(nums,maxor,index+1,curror|nums[index]);
        int nottake = solve(nums,maxor,index+1,curror);
        return take+nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(auto i : nums) maxor|=i;
        return solve(nums,maxor,0,0);
        // cout<<maxor;
        
    }
};