class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,ans=0;
        int lmax=INT_MIN,rmax=INT_MIN;
        while(l<r){
            lmax = max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
        
    }
};