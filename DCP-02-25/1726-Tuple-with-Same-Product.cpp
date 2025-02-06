class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int> temp;
        long long ans=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(temp.find(nums[i]*nums[j])!=temp.end()) ans+= 8*temp[nums[i]*nums[j]];
                temp[nums[i]*nums[j]]++;
            }
        }
        
        return ans;
        
    }
};