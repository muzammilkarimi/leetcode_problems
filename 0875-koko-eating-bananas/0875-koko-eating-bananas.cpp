class Solution {
public:
    bool ispossible(vector<int>& piles, int h, long long mid){
        int count=0;
        for(int i: piles){
            if(i<=mid) count++;
            else count+=ceil(static_cast<double>(i)/mid);
        }
        return count<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long total =0;
        for(auto i:piles) total+=i;
        long long l=1, r=total;
        long long ans=INT_MAX;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(ispossible(piles,h,mid)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
