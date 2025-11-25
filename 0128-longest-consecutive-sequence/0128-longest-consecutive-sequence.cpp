class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(int i=0; i<n; i++) s.insert(nums[i]);
        int ans=0,count=0;
        for(int i:s){
            if(s.count(i-1)==0){
                count=1;
                int x=i+1;
                while(s.count(x)){
                    x++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
        
    }
};