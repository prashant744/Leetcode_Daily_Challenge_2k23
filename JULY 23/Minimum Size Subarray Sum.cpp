class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int l=0,s=0;
       int ans=nums.size();
       for(int it:nums){
           s+=it;
       } 
       if(s<target)return 0;

       int str=0;
       for(int i=0;i<nums.size();i++){
           str+=nums[i];
           while(str-nums[l]>=target){
               str-=nums[l++];
           }
            if(str>=target){
                ans=min(ans,i-l+1);
            }
        }
        return ans;
    }
};