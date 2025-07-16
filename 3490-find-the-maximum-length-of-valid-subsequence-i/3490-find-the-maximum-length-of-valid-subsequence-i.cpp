class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenc=0,oddc=0,eve=0,odd=0;
        for(int i:nums){
            if(i%2==0) {evenc++;
            eve=max(eve,odd+1);
            }
            else {oddc++;odd=max(odd,eve+1);}
        }
        return max({oddc,evenc,eve,odd});

        
    }
};