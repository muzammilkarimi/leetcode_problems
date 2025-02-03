class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        for(int i=0; i<nums.size(); i++){
            int inct=1,dect=1;
            for(int j=i; j<nums.size()-1; j++){
                if(nums[j]<nums[j+1]) inct++;
                else{
                    inc=max(inc,inct);
                    inct=1;
                }
                if(nums[j]>nums[j+1]) dect++;
                else{
                    dec=max(dec,dect);
                    dect=1;
                }
            }
            inc=max(inc,inct);
            dec=max(dec,dect);
        }
        return max(inc,dec);
        
    }
};