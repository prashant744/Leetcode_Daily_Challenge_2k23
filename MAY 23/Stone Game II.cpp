class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int dp[101][101];
        int sum[101];
        int n=piles.size();
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        sum[n-1]=piles[n-1];

        for(int i=n-2;i>=0;i--){
            sum[i]=piles[i]+sum[i+1];
        }

        for(int i=n-1;i>=0;i--){
            for(int m=1;m<=n;m++){
                if(i+2*m>=n){
                    dp[i][m]=sum[i];
                }else{
                    for(int x=1;x<=2*m;x++){
                        dp[i][m]=max(dp[i][m],sum[i]-dp[i+x][max(m,x)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};