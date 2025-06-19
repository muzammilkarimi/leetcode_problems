class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        int n=nums.size();
        for(int i:nums){
            count[i]++;
            if(count[i]>(n/2)) return i;
        }
        return 0;

        
    }
};