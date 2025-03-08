class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0,ans=101,left=0,right=0,n=blocks.size();
        while(right<n){
            if((right-left)<k){
                if(blocks[right]=='W') count++;
                right++;
            }
            else{
                // cout<<count<<" ";
                ans=min(ans,count);
                if(blocks[left]=='W') count--;
                left++;
                if(blocks[right]=='W') count++;
                right++;
                if(count==0)return 0;
            }
        }
        return min(count,ans);

        
    }
};