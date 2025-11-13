class Solution {
public:
    int maxOperations(string s) {
        int one=0,ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                while(i+1<s.size() and s[i+1]=='0') i++;
                ans+=one;

            }
            else one++;
        }
        return ans;

        
    }
};