class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> count;
        for(int i:nums){
            count[i]++;
        }
        int temp=0;
        for(auto i:count){
            temp+=i.second/2;
        }
        return temp==n/2;
        
    }
};