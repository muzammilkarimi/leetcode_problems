class Solution {
public:
    bool isVowel(char s){
        return s=='a' or s=='e' or s=='i' or s=='o' or s=='u';
    }
    int find(string s,int k){
        unordered_map<char,int> freq;
        int count=0;
        int i=0,j=0;
        while(j<s.size())
        {
            if(!isVowel(s[j]))
            {
                i=j+1;
                j++;
                freq.clear();
                continue;
            }
            freq[s[j++]]++;
            while(freq.size()>k)
            {
                freq[s[i]]--;
                if(freq[s[i]]==0)
                    freq.erase(s[i]);
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    int countVowelSubstrings(string word) {
        return find(word,5)-find(word,4);
    }
};