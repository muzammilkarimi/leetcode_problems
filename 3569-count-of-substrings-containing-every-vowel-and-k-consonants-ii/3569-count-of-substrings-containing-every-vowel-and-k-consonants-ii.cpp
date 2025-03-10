class Solution {
public:
    long long int find(string word,int k){
        int i=0,j=0,countk=0;
        long long ans=0;
        map<char,int> vowelcount;
        while(j<word.size()){
            if(word[j]=='a' or word[j]=='e' or word[j]=='i' or word[j]=='o' or word[j]=='u') vowelcount[word[j]]++;
            else countk++;
            while(vowelcount.size()==5 and countk>=k){
                ans+=word.size()-j;
                if(vowelcount.find(word[i])!=vowelcount.end()){
                    vowelcount[word[i]]--;
                    if(vowelcount[word[i]]==0) vowelcount.erase(word[i]);
                }
                else countk--;
                i++;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return find(word,k)-find(word,k+1);
        
    }
};