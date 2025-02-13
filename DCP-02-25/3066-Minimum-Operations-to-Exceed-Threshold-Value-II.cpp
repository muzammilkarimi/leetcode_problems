class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> minheap(nums.begin(),nums.end());
        int ans=0;
        while(!minheap.empty()){
            ll min1=minheap.top();
            minheap.pop();
            if(min1>=k) break;
            ll min2=minheap.top();
            minheap.pop();
            minheap.push(min(min1,min2)*2+max(min1,min2));
            ans++;
        }
        return ans;
        
        
    }
};