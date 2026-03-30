class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minele = *min_element(nums.begin(),nums.end());
        int maxele = *max_element(nums.begin(),nums.end());
        vector<int> count(maxele-minele+1,0);
        for(int i:nums){
            count[i-minele]++;
        }
        for(int i=count.size()-1; i>=0; i--){
            k-=count[i];
            if(k<=0) return i+minele;
        }
        return minele;
    }
};