class Solution {
public:
    bool check(vector<int> count,int num){
        for(int i=1; i<=3; i++){
            int n=num%10;
            num/=10;
            if(count[n]>=1) count[n]--;
            else return false;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10,0);
        for(int i:digits){
            count[i]++;
        }
        vector<int> ans;
        int mini=*min_element(digits.begin(),digits.end());
        mini=mini==0?mini=1:mini;
        for(int i=mini*100; i<1000; i+=2){
            if(check(count,i)) ans.push_back(i);
        }
        return ans; 
    }
};