class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int ans=0,st=0;
        unordered_map<int,int> hash;
        for(int i=0; i<arr.size(); i++){
            hash[arr[i]]++;
            while(hash.size()>2){
                hash[arr[st]]--;
                if(hash[arr[st]]==0){
                    hash.erase(arr[st]);
                }
                st++;
            }
            ans=max(ans,i-st+1);
        }
        return ans;
        
    }
};