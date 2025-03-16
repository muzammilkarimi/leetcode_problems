class Solution {
public:
    bool check(long long mid,vector<int>& ranks, int cars){
        long long count=0;
        for(int r: ranks){
            long long t=mid/r;
            count += floor(sqrt(t));
        }
        return count>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long temp = *max_element(ranks.begin(),ranks.end());
        long long r = temp*cars*cars;
        long mid,ans;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(mid,ranks,cars)){
                ans=mid;
                r = mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
        
    }
};