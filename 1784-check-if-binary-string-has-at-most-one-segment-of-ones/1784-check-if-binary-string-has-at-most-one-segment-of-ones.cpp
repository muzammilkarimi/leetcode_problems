class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s.size()==1 and s[0]=='1') return true;
        for(int i=1; i<s.size(); i++){
            if((s[i-1]=='0') and (s[i]=='1')) return false;
        }
        return true;
    }
};