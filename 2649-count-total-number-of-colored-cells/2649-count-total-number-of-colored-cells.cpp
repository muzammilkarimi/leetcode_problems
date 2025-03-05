class Solution {
public:
    long long coloredCells(int n) {
        return ((4LL*(n-1)*n)/2)+1;
        // 1 5 13 25
        // (4*n-1*n)/2+1
 
        
    }
};