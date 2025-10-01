class Solution {
public:
    int numWaterBottles(int numb, int nume) {
        int ans=numb,empty=numb,remain=0;
        while(empty>=nume){
            ans+=empty/nume;
            remain=empty%nume;
            empty/=nume;
            empty+=remain;
        }
        return ans;
    }
};