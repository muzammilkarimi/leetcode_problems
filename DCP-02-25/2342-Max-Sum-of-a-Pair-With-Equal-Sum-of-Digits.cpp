class Solution {
public:
    int digitsum(int n){
        int temp=0;
        while(n){
            temp+=n%10;
            n/=10;
        }
        return temp;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> freq;
        for(int i=0; i<n; i++){
            freq[digitsum(nums[i])].push_back(nums[i]);
        }
        int ans=-1;
        for(auto &i:freq){
            if(i.second.size()>=2){
                sort(i.second.begin(),i.second.end(),greater<int>());
                ans=max(ans,i.second[0]+i.second[1]);
            }
        }
        return ans;
    }
};