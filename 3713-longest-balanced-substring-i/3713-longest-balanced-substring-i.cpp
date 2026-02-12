class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        for (int j = 0; j < s.size(); j++) {
            int mx = 0;
            map<char, int> count;
            for (int i = j; i < s.size(); i++) {
                count[s[i]]++;
                if (mx < count[s[i]])
                    mx = count[s[i]];
                if (mx * count.size() ==  i-j + 1) {
                    ans = max(ans,i-j + 1);
                }
            }
        }
        return ans;
    }
};