class Solution {
public:
    long long dp[100002];
    long long helper(vector<vector<int>>&ques,int i){
        if(i>=ques.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(ques[i][0]+helper(ques,i+1+ques[i][1]),helper(ques,i+1));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return helper(questions,0);
    }
};