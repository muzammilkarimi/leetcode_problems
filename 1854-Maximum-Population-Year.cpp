class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> list;
        for(auto& p:logs){
            list[p[0]]++;
            list[p[1]]--;
        }
        int ans=0,count=0,year;
        for(auto& y:list){
            count+=y.second;
            // cout<<count;
            if(count>ans){
                ans=count;
                year=y.first;
            }
        }
        
        return year;
    }
};