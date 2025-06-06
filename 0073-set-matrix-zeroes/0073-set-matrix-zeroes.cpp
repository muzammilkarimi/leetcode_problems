class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        bool r=false, c=false, p=false;
        for(int i=0; i<m; i++)
            if(a[i][0]==0) c=1;
        for(int i=0; i<n; i++)
            if(a[0][i]==0) r=1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(a[i][j]==0) {
                    a[0][j] = 0;
                    a[i][0] = 0;
                }                    
            }
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(a[i][0] == 0)
                    a[i][j] = 0;
                if(a[0][j] == 0)
                    a[i][j] = 0;
            }
        }
        if(r) {
            for(int i=0; i<n; i++)
                a[0][i] = 0;
        } 
        if(c) {
            for(int i=0; i<m; i++)
                a[i][0] = 0;
        }
        // return;
    }
};