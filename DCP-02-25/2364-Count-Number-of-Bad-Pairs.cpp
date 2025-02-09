class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        long long goodpairs=0;
        for(int i=0; i<n; i++){
            if(freq.count(nums[i]-i)!=0)
                goodpairs+=freq[nums[i]-i];
            freq[nums[i]-i]++;
        }
        long long badpairs = n*(n-1LL)/2 - goodpairs;
        return badpairs;

        
    }
};