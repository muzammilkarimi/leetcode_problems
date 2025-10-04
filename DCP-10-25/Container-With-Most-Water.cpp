class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1,n=heights.size();
        int ans=0;
        while(l<r){
            ans=max(ans,(r-l)*min(heights[l],heights[r]));

            if(heights[l]<heights[r])
            l++;
            else
            r--;
        }
        return ans;
        
    }
};