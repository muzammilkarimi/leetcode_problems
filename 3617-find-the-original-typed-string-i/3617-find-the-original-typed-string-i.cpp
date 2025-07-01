class Solution {
public:
    int possibleStringCount(string word) {
        int ans=0,count=1;
        // char c=word[0];
        for(int i=1; i<word.size(); i++){
            if(word[i]!=word[i-1]){
                ans=ans+count-1;
                count=1;
            }
            else count++;
        }
        return ans+count;
        
    }
};