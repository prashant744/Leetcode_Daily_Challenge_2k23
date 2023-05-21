class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j, set<pair<int,int>> &graph){
        if(min(i,j) < 0 || max(i,j)>= grid.size() || !grid[i][j] || graph.count({i,j})) 
            return;
        
        graph.insert({i,j});
        grid[i][j]=0;
        helper(grid,i+1,j,graph);
        helper(grid,i-1,j,graph);
        helper(grid,i,j+1,graph);
        helper(grid,i,j-1,graph);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int,int>>graph1,graph2;
        bool graph=true;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]){
                    if(graph){
                        helper(grid,i,j,graph1),graph=0;
                    }else{
                        helper(grid,i,j,graph2);
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(auto [x1,y1]:graph1){
            for(auto [x2,y2]:graph2){
                ans=min(ans,abs(x1-x2)+abs(y1-y2)-1);
            }
        }
        return ans;
    }
};