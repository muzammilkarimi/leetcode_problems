class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> mp;
        long long rem=1%k;
        int ans = 1;
        while(1){
            if(rem==0) return ans;
            if(mp.count(rem)) return -1;
            mp.insert(rem);
            rem=(rem*10+1)%k;
            ans++;
        }
        return -1;
        
    }
};