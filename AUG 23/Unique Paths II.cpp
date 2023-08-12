class Solution {
public:
    int helper(int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(m>=obstacleGrid.size() || n>=obstacleGrid[0].size() || obstacleGrid[m][n]==1){
            return 0;
        }
        if(m==obstacleGrid.size()-1 && n==obstacleGrid[0].size()-1){
            return 1;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        int down=helper(m+1,n,obstacleGrid,dp);
        int right=helper(m,n+1,obstacleGrid,dp);
        int ans=down+right;
        return dp[m][n]=ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return helper(0,0,obstacleGrid,dp);
    }
};