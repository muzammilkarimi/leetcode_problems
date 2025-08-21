class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size(), l = 0, r = 0, i = 0;
        while (i < n) {
            while (i < n and s[i] == ' ') {
                i++;
                if (i == n)
                    break;
            }
            if(i==n) break;
            while (i < n and s[i] != ' ') {
                s[r++] = s[i++];
            }
            reverse(s.begin() + l, s.begin() + r);
            s[r++] = ' ';
            l = r;
            // i++;
        }
        if (r > 0) r--;
        s.resize(r);
        return s;
    }
};