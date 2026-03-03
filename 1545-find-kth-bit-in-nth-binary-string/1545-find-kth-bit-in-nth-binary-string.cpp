class Solution {
public:
    void rev_inv(string &s){
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        reverse(s.begin(),s.end());
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1; i<n; i++){
            string temp = s;
            rev_inv(temp);
            s+='1'+ temp;
        }
        return s[k-1];

        
    }
};