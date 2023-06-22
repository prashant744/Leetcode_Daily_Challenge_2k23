class Solution {
public:
    int helper(vector<int>& prices,int index,bool hold,int fee,vector<vector<int>>& dp){
        if(index==prices.size())return 0;
        if(!hold){
            if(dp[index][0]!=-1) return dp[index][0];
            int buy=0,wait=0;
            buy=-prices[index]+helper(prices,index+1,true,fee,dp);
            wait=helper(prices,index+1,hold,fee,dp);
            return dp[index][0]=max(buy,wait);

        }else{
            if(dp[index][1]!=-1) return dp[index][1];
            int sell=0,wait=0;
            sell=prices[index]-fee+helper(prices,index+1,false,fee,dp);
            wait=helper(prices,index+1,hold,fee,dp);
            return dp[index][1]=max(sell,wait);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        int ans=helper(prices,0,false,fee,dp);
        return ans;
    }
};