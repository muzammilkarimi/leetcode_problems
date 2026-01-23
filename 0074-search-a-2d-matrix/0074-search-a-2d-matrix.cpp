class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int r=mat.size(),c=mat[0].size();
        int l=0,h=r*c-1;
        while(l<=h){
            int mid = (l+h)/2;
            int row=mid/c,col=mid%c;
            if(mat[row][col]==t) return true;
            else if(mat[row][col]>t) h=mid-1;
            else l=mid+1;
        }
        return false;
    }
};