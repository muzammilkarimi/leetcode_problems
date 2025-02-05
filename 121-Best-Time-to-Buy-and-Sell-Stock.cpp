class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,min_e=INT_MAX;
        for(int i=0; i<prices.size(); i++){
            min_e=min(min_e,prices[i]);
            ans=max(ans,prices[i]-min_e);
        }
        return ans;
    }
};