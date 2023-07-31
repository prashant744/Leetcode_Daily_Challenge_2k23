class Solution {
public:

    int get_min(string&s1, string&s2,int i ,int j , vector<int>&Sufix1, vector<int>&Sufix2,vector<vector<int>>&dp){
        if(i >= s1.size()  && j >= s2.size()) return 0;
        if(i >= s1.size()  && j < s2.size()) return Sufix2[j];
        if(i < s1.size()  && j >= s2.size()) return Sufix1[i];

        if(dp[i][j] != -1 ) return dp[i][j];
        int sum = 0;

        if(s1[i] == s2[j])
            sum += get_min(s1,s2,i+1,j+1,Sufix1,Sufix2,dp);
        else 
            sum += min( s1[i] + get_min(s1,s2,i+1,j,Sufix1,Sufix2,dp),s2[j] + get_min(s1,s2,i,j+1,Sufix1,Sufix2,dp));

        return dp[i][j] = sum;
        }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(n2+1,-1));
        vector<int>Sufix1(n);
        vector<int>Sufix2(n2);

        Sufix1[n-1] = s1[n-1];
        Sufix2[n2-1] = s2[n2-1];

        for(int i = n-2;i>=0;i--) Sufix1[i] = Sufix1[i+1] + s1[i];
        for(int i = n2-2;i>=0;i--) Sufix2[i] = Sufix2[i+1] + s2[i];

        return get_min(s1,s2,0,0,Sufix1,Sufix2,dp);
        
    }
};