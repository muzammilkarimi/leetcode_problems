class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long totalpairs = n*(n-1LL)/2;
        for(int i=0; i<n; i++)
            nums[i]-=i;
        sort(nums.begin(),nums.end());
        long long goodpairs=1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]) goodpairs++;
            else{
                totalpairs-=goodpairs*(goodpairs-1)/2;
                goodpairs=1;
            }
        }
        totalpairs-=goodpairs*(goodpairs-1)/2;
        return totalpairs;
        // unordered_map<int,int> freq;
        // long long goodpairs=0;
        // for(int i=0; i<n; i++){
        //     if(freq.count(nums[i]-i)!=0)
        //         goodpairs+=freq[nums[i]-i];
        //     freq[nums[i]-i]++;
        // }
        // long long badpairs = n*(n-1LL)/2 - goodpairs;
        // return badpairs;

        
    }
};