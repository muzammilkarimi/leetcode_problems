class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word(wordDict.begin(),wordDict.end());
        int maxlen = 0;
        for(string w:wordDict){
            maxlen = max(maxlen,(int)w.length());
        }
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        for(int i=1; i<=s.size(); i++){
            for(int j = i-1; j>=max(0,i-maxlen); j--){
                if(dp[j] and word.find(s.substr(j,i-j)) != word.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};