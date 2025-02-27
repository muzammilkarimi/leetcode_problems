class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxcount=0,n=arr.size();
        unordered_set<int> set(arr.begin(),arr.end());
        for(int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
                int a=arr[i],b=arr[j],count=2;
                while(set.count(a+b)>0){
                    int sum=a+b;
                    a=b;
                    b=sum;
                    count++;
                }
                if(count>2) maxcount=max(maxcount,count);
            }
        }
        return maxcount;
        
    }
};