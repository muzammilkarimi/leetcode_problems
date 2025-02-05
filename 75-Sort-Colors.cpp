class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two=nums.size()-1,zero=0,i=0,n=nums.size();
        while(i<=two){
            if(nums[i]==0) {
                swap(nums[i++],nums[zero]);
                zero++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[two]);
                two--;

            } 
            else i++;
        }
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==0) zero++;
        //     else if(nums[i]==1) one++;
        //     else two++;
        // }
        // int ind=0;
        // while(zero--){
        //     nums[ind++]=0;
        // }
        // while(one--){
        //     nums[ind++]=1;
        // }
        // while(two--){
        //     nums[ind++]=2;
        // }

        
    }
};