class Solution {
public:
    bool isDistinct(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        return s.size() == arr.size();
    }
    int minimumOperations(vector<int>& nums) {
        if (isDistinct(nums))
            return 0;

        int count = 0,temp;
        while (1) {
            unordered_map<int, int> freq;
            temp=0;
            for (int n : nums) if(++freq[n]==2) temp++;
            if(temp==0) break;
            nums.erase(nums.begin(),nums.begin()+min(3,(int)nums.size()));
            count++;
        }
        return count;
    }
};