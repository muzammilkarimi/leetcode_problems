class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> seive(right+1,true);
        vector<int> primes;
        for(int i=2; i*i<=right; i++){
            if(seive[i]){
                for(int j=2; i*j<=right; j++)
                    seive[i*j]=false;
            }
        }
        for(int i=max(2,left); i<=right; i++){
            if(seive[i]) primes.push_back(i);
        }
        int a=0,b=INT_MAX;
        for(int i=1; i<primes.size(); i++){
            if((b-a)>(primes[i]-primes[i-1])){
                a=primes[i-1];
                b=primes[i];
            }
        }

        if(a==0) return {-1,-1};
        else return {a,b};
        
    }
};