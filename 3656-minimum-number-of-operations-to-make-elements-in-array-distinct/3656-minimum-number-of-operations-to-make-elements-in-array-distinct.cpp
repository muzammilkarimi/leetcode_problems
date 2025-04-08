class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        map<int,int> mp;
        for(int i=nums.size()-1; i>=0; i--){
            if(++mp[nums[i]]>1) return (i+3)/3;
        }
        return 0;
        
    }
};