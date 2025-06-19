class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> count;
        for(int n:nums){
            if(count[n]!=0) return true;
            count[n]++;
        }
        return false;
        
    }
};