class Solution {
public:
    bool isvalid(int x,int y, int row,int col){
        return (x>=0 and x<row and y>=0 and y<col);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row=isWater.size();
        int col=isWater[0].size();
        vector<vector<int>> ans(row,vector<int>(col,-1));
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first,y=curr.second;
            for(int i=0; i<4; i++){
                int X=x+dir[i].first;
                int Y=y+dir[i].second;
                if(isvalid(X,Y,row,col) and ans[X][Y]==-1){
                    ans[X][Y]=ans[x][y]+1;
                    q.push({X,Y});
                }
            }
        }

        return ans;
    }
};