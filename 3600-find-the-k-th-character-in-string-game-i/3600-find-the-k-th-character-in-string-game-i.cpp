class Solution {
public:
    char kthCharacter(int k) {
        if(k==1) return 'a';
        string s="a";
        while(s.size()<k){
            int size=s.size();
            for(int j=0; j<size and s.size()<k; j++){
                if(s[j]=='z') s+='a';
                else s+=(char)(s[j]+1);
            }
        }
        return s[k-1];
    }
};