class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> arr(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        map<int,int> temp;
        int n=nums.size();
        for(int i=n-1; i>=n-k; i--){
            temp[arr[i]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(temp.count(nums[i]) and temp[nums[i]]>0){
                ans.push_back(nums[i]);
                temp[nums[i]]--;
            }
        }
        return ans;
    }
};