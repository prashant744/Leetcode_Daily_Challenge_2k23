class Solution {
public:
    bool check(vector<int>c1,vector<int>c2){
        long long rSquare=pow(c1[2],2);
        long xDiff=pow(c1[0]-c2[0],2);
        long yDiff=pow(c1[1]-c2[1],2);

        if(xDiff+yDiff<=rSquare){
            return true;
        }
        return false;
    }

    void dfs(vector<int>graph[],int vertex,vector<bool>&visited,int& cnt){
        visited[vertex]=true;
        cnt++;
        for(int child:graph[vertex]){
            if(!visited[child]){
                dfs(graph,child,visited,cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int v=bombs.size();
        vector<int>graph[v];

        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i!=j){
                    if(check(bombs[i],bombs[j])){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        vector<bool>visited(v,false);

        int maxBombs=INT_MIN;
        for(int i=0;i<v;i++){
            int cnt=0;
            dfs(graph,i,visited,cnt);

            maxBombs=max(maxBombs,cnt);
            for(int j=0;j<v;j++){
                visited[j]=false;
            }
        }
        return maxBombs;
    }
};