class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<int, int> vert, hor;
        for(auto &x: rectangles) {
            vert[x[1]+1] += 1;
            vert[x[3]] -= 1;
        }
        int curr = 0;
        int ans = 0;
        for(auto &x: vert) {
            curr += x.second;
            if(curr == 0)
                ans++;
        }
        --ans;
        if(ans>=2)
            return true;
        
        ans = 0;
        curr = 0;
        for(auto &x: rectangles) {
            hor[x[0]+1] += 1;
            hor[x[2]] -= 1;
        }
        for(auto &x: hor) {
            curr += x.second;
            if(curr == 0)
                ans++;
        }
        --ans;
        if(ans>=2)
            return true;
        return false;
    }
};