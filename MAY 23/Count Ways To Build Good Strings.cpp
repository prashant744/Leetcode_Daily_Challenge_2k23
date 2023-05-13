class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int MOD=1e9+7;
        vector<int> dp(high + max(zero, one)+1, 0);

        for(int i=high;i>=0;i--){
            dp[i]=(dp[i+zero]+dp[i+one])%MOD;

            if(low<=i && i<=high){
                dp[i]=(dp[i]+1)%MOD;
            }
        }
        return dp[0];
    }
};