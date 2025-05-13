class Solution {
    const int mod = 1e9+7;
    int mod_add(int a,int b){a=a%mod; b=b%mod; return (((a+b)%mod) + mod)%mod;}
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> count(26,0);
        for(char ch:s) count[ch-'a']++;
        while(t--){
            vector<int> cur(26,0);
            for(int j=0; j<26; j++){
                if(j==25 and count[j]>0){
                    cur[0] = mod_add(cur[0],count[j]);
                    cur[1] = mod_add(cur[1], count[j]);
                }
                else if(j<25){
                    cur[j+1] = mod_add(cur[j+1],count[j]);
                }
            }
            for(int i=0; i<26; i++) count[i]=cur[i];
        }
        int ans = 0;
        for(int i:count) ans = mod_add(ans,i);
        return (int)ans;
    }
};