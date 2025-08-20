class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        int n = intv.size();
        vector<vector<int>> res;
        sort(intv.begin(), intv.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        res.push_back(intv[0]);
        for(int i=1; i<n; i++){
            if(intv[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1],intv[i][1]);
            }
            else res.push_back(intv[i]);
        }
        // for()
        return res;
    }
};
