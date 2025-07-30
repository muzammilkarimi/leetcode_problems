class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        map<int,int> hash;
        hash[sum]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()){
                ans+=hash[sum-k];
            }
            hash[sum]++;
        }
        return ans;
        
    }
};