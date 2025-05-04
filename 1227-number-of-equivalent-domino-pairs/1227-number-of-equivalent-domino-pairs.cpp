class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mpp;
        int count=0;
        for(auto & n:dominoes){
            if(n[0]>n[1]) swap(n[0], n[1]);
            count+=mpp[make_pair(n[0],n[1])]++;
        }
        return count;
        
    }
};