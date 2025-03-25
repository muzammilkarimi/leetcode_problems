class Solution {
public:
    bool checkCuts(vector<vector<int>>& rectangles, bool isVertical) {
        map<int, int> cuts;
        
        for (auto &x : rectangles) {
            if (isVertical) {
                cuts[x[1] + 1]++;
                cuts[x[3]]--;
            } else {
                cuts[x[0] + 1]++;
                cuts[x[2]]--;
            }
        }

        int curr = 0, ans = 0;
        for (auto &x : cuts) {
            curr += x.second;
            if (curr == 0)
                ans++;
        }
        return --ans >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles, true) || checkCuts(rectangles, false);
    }
};
