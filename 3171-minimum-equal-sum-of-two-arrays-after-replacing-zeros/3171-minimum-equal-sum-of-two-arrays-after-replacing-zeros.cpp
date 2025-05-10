class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zero1=0,zero2=0,sum1=0,sum2=0;
        for(int x:nums1){
            if(x==0) zero1++;
            sum1+=x;
        }
        for(int x:nums2){
            if(x==0) zero2++;
            sum2+=x;
        }
        if(zero1==0 and zero2==0) return sum1==sum2?sum1:-1;
        else if(zero2==0) return sum1+zero1<=sum2?sum2:-1;
        else if(zero1==0) return sum2+zero2<=sum1?sum1:-1;

        return max(sum1+zero1,sum2+zero2);

        
    }
};