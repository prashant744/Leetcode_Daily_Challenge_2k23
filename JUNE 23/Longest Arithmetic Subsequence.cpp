class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int result=0;
        vector<unordered_map<int,int>>dp(nums.size());

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                dp[i][diff]=dp[j].count(diff)>0?dp[j][diff]+1:2;
                result=max(result,dp[i][diff]);
            }
        }
        return result;
    }
};