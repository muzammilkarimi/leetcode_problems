class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,count=0;
        unordered_map<char,int> lettercnt;
        for(int r=0; r<s.size(); r++){
            lettercnt[s[r]]++;
            while(lettercnt['a']>0 and lettercnt['b']>0 and lettercnt['c']>0){
                count+=s.size()-r;
                lettercnt[s[l++]]--;
            }
        }
        return count;
        
    }
};