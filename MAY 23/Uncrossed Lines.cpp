class Solution {
public:
    int dp[505][505];
    int helper(int n,int m,vector<int>&nums1,vector<int>&nums2){
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(nums1[n]==nums2[m]){
            return 1+helper(n-1,m-1,nums1,nums2);
        }
        return dp[n][m]=max(helper(n,m-1,nums1,nums2),helper(n-1,m,nums1,nums2));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int n=nums1.size()-1;
        int m=nums2.size()-1;

        return helper(n,m,nums1,nums2);
    }
};