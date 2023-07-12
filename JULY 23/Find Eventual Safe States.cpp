class Solution {
public:

     bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis, vector<int>& pathvis,vector<int> & safe){
         vis[node]=1;
         pathvis[node]=1;
          for(auto it : graph[node]){
              if(vis[it]!=1){
                   if(dfs(it,graph,vis,pathvis,safe)==true){
                         safe[it]=0; 
                        return true;
                   }
              }else if(pathvis[it]==1){
                         safe[it]=0; 
                        return true;
              }
          }
         safe[node]=1;
         pathvis[node]=0;
         return false;
     }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n+1,0);
        vector<int> pathvis(n+1,0);
        vector<int> safe(n+1,0);
        vector<int> safenode;
        //Traversing the graph vector for all nodes
        for(int i=0;i<n;i++){
             if(vis[i]!=1){
                 dfs(i,graph,vis,pathvis,safe);
             }
        }
        //Traversing the safe vector to find safe nodes
        for(int i=0;i<n;i++){
            if(safe[i]==1){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};