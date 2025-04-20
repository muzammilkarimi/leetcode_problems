class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> cnt;
        int ans=0;
        for(int n:answers){
            cnt[n]++;
        }
        for(auto c:cnt){
            if(c.first==0) {ans+=c.second; continue;}
            ans+=ceil(c.second/((c.first+1)*1.0))*(c.first+1);
        }
        return ans;
        
    }
};