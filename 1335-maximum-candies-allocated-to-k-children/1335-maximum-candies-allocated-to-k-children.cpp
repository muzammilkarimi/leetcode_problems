class Solution {
public:
    bool check(vector<int>& candies,int mid, long long k){
        long long div=0;
        for(int i=0;i<candies.size(); i++){
            div+=candies[i]/mid;
        }
        cout<<div;
        if(div>=k) return true;
        else return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,n=candies.size(),mid,ans=0;
        auto mx=max_element(candies.begin(),candies.end());
        int r=*mx+1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(check(candies,mid,k)){
                cout<<"true";
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
        
    }
};