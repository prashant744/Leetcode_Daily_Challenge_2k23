class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),m=2*k+1;
        long long sum=0;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i>=m){
                sum-=nums[i-m];
            }
            if(i>=m-1){
                ans[i-k]=sum/m;
            }
        }
        return ans;
    }
};