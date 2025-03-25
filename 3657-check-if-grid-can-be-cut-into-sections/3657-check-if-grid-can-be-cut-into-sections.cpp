#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkCuts(vector<vector<int>>& rectangles, bool isVertical) {
        unordered_map<int, int> cuts; // Using unordered_map for O(1) insert/delete

        for (auto &x : rectangles) {
            if (isVertical) {
                cuts[x[1] + 1]++;
                cuts[x[3]]--;
            } else {
                cuts[x[0] + 1]++;
                cuts[x[2]]--;
            }
        }

        vector<pair<int, int>> sortedCuts(cuts.begin(), cuts.end());
        sort(sortedCuts.begin(), sortedCuts.end()); // O(N log N) sorting

        int curr = 0, ans = 0;
        for (auto &x : sortedCuts) {
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
