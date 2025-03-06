class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> count;
        for(int i=1; i<=n*n; i++){
            count[i]=0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                count[grid[i][j]]++;
            }
        }
        int a,b;
        for(auto & num:count){
           if(num.second==2) a=num.first;
           if(num.second==0) b=num.first;

        }

        return {a,b};
        
    }
};