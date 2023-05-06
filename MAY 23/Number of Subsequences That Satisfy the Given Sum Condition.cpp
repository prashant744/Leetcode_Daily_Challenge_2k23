class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD=1e9+7,n=nums.size();
        vector<int>pow={1};
        for(int i=0;i<n;i++){
            pow.push_back((pow.back()*2)%MOD);
        }
        int left=0,right=n-1,ans=0;
        sort(nums.begin(),nums.end());

        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans=(ans+pow[right-left])%MOD;
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};