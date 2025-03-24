class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int prev = 0;
        int ans = 0;
        for(auto &x: meetings) {
            if(x[0]>prev)
                ans += x[0] - prev - 1;
            prev = max(prev, x[1]);
        }
        ans += days - prev;
        return ans;     
    }
};