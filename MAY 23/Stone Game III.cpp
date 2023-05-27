class Solution {
public:
    int n;
    vector<int>dp;
    int helper(vector<int>&stoneValue,int curr){
        if(curr==n){
            return 0;
        }

        if(dp[curr]>INT_MIN){
            return dp[curr];
        }
        int sum=0;
        for(int i=curr;(i<curr+3) && (i<n);i++){
            sum+=stoneValue[i];
            dp[curr]=max(dp[curr],sum-helper(stoneValue,i+1));
        }
        return dp[curr];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=(int)stoneValue.size();
        dp.resize(n,INT_MIN);
        int score=helper(stoneValue,0);
        
        if(score>0){
            return "Alice";
        }else if(score<0){
            return "Bob";
        }else{
            return "Tie";
        }
    }
};