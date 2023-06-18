class Solution {
public:
    bool check(int i,int j,int m,int n){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int val=i*n+j;
                pq.push({-grid[i][j],val});
            }
        }
        long long ans=0;
        int mod=1e9+7;
        vector<vector<int>>dp(m,vector<int>(n,1));
        
        while(pq.size()>0){
            int i=pq.top().second/n;
            int j=pq.top().second%n;
            pq.pop();
            int x[]={1,0,-1,0};
            int y[]={0,-1,0,1};

            for(int l=0;l<4;l++){
                if(check(i+x[l],j+y[l],m,n) && grid[i+x[l]][j+y[l]]<grid[i][j]){
                    dp[i][j]+=dp[i+x[l]][j+y[l]];
                    dp[i][j]%=mod;
                }
            }
            ans=(ans+dp[i][j])%mod;
        }
        return ans;
    }
};