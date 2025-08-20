class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        int sum=0;
        for(int i=0; i<row; i++){
            dp[i][0]=mat[i][0];
            sum+=dp[i][0];
        }
        for(int i=1; i<col; i++){
            dp[0][i]=mat[0][i];
            sum+=dp[0][i];
        }
        
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(mat[i][j]!=0) {
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    sum+=dp[i][j];
                }
            }
        }
        return sum;
        
    }
};