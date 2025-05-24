class Solution {
public:
    bool check(string str, char x){
        for(auto s:str){
            if(s==x) return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0; i<words.size(); i++){
            if(check(words[i],x)) ans.push_back(i);
        }
        return ans;

        
    }
};