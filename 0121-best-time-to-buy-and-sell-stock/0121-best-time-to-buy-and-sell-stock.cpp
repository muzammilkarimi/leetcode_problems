class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell=0,profit=0;
        for(int i=0; i<prices.size(); i++){
            buy = min(buy,prices[i]);
            profit=max(profit,prices[i]-buy);
        }
        return profit;
        
    }
};