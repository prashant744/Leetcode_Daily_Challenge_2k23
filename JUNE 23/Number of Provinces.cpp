class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int> adj[]){
        if(vis[node])return;
        vis[node]=1;
        for(auto val:adj[node]){
            dfs(val,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<int>vis(n+1,0);
        // create Adj list
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] &&i!=j){
                    adj[i+1].push_back(j+1);
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};