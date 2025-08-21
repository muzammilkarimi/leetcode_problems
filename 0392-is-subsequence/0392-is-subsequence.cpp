class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        int i=0,j=0;
        while(i<s.length() and j<t.size()){
            if(s[i]!=t[j]) j++;
            else {
                i++;
                j++;
            }
            if(i==s.size()) return true;
        }
        return false;

        
    }
};