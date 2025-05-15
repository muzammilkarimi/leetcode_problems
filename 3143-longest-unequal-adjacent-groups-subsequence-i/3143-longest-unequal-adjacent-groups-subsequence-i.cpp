class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,vector<int>& groups) {
        
        for (int i = 0; i < words.size() - 1;) {
            if (groups[i] == groups[i + 1]) {
                words.erase(words.begin() + i);
                groups.erase(groups.begin() + i);
            } else
                i++;
        }
        return words;
        //     vector<string> ans;
        //     vector<int> gr;
        //     ans.push_back(words[0]);
        //     gr.push_back(groups[0]);
        //     int count=1;
        //     for(int i=1; i<words.size(); i++){
        //         if(groups[i]!=gr[count-1]){
        //             ans.push_back(words[i]);
        //             gr.push_back(groups[i]);
        //             count++;
        //         }
        //     }
        //     return ans;
        }
    };