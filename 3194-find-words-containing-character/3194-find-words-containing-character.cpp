class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int i=0;
        for (auto str:words) {
            for (auto s : str) {
                if (s == x){
                    ans.push_back(i);
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};