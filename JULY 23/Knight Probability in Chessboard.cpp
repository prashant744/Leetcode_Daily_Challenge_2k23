class Solution {
    vector<vector<int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    map<vector<int>,double> mp;

    double f(int r, int c, int k, int n){
        double ans = 0;
        if(k == 0) return 1.0;  // as there are no more steps to take, it's a successful path
        vector<int> dp = {r, c, k}; 
        if(mp.find(dp) != mp.end()) return mp[dp];

        for(int i = 0;i < 8;i++){
            int nx = r + dir[i][0], ny = c + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            ans += f(nx, ny, k-1, n) / 8.0;  // probability of each step as there are 8 possible steps
        } 
        return mp[dp] = ans;
    }
public:
    double knightProbability(int n, int k, int r, int c) {
        return f(r, c, k, n); // no need to divide by total paths as we are calculating the probability in the function f itself
    }
};