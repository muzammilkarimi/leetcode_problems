class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row=mat.size(),col=mat[0].size(),ans=0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            int c=0;
            for(int j=col-1; j>=0; j--){
                if(mat[i][j]) c++;
                else c=0;
                dp[i][j]=c;
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int m=INT_MAX;
                for(int k=i; k<row; k++){
                    m=min(m,dp[k][j]);
                    ans+=m;
                }
            }
        }
        return ans;
    }
};