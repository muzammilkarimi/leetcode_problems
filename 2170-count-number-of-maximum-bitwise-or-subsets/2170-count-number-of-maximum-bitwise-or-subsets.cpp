class Solution {
public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
    int n = arr.size();
    int subsetCount = pow(2, n); // 2^n subsets
    vector<vector<int>> allSubsets;
    
    // Iterate over all possible subsets
    for (int i = 0; i < subsetCount; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            // Check if the j-th element is in the i-th subset
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        allSubsets.push_back(subset);
    }
    
    return allSubsets;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0,ans=0;
        vector<int> subset;
        for(auto i : nums) maxor = maxor | i;
        // cout<<maxor;
        vector<vector<int>> allsubsets=findSubsets(nums);
        for(const auto& s : allsubsets){
            int tempor = 0;
            for(int j:s){
                tempor = tempor | j;
            }
            if(tempor==maxor) ans++;
        }

        return ans;

    }
};