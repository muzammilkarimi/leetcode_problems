class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count=0,n=colors.size(),prev=colors[0],gr=1;
        for(int i=1; i<n+k-1; i++){
            gr=(colors[i%n]==prev)?1:gr+1;
            if(gr>=k)count++;
            prev=colors[i%n];
        }
        return count;
        
    }
};