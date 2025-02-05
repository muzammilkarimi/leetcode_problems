class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;

        // for(int i=0; i<s1.length(); i++){
        //     for(int j=i; j<s1.length(); j++){
        //         swap(s1[i],s1[j]);
        //         if(s1==s2) return true;
        //         swap(s1[i],s1[j]);
        //     }
        // }
        int first,count=0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                count++;
                if(count==1)first=i;
                else{
                    swap(s1[first],s1[i]);
                    break;
                }
            }
        }
        return s1==s2;
        
    }
};