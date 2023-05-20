class Solution {
    void dfs(string& s,string& d,unordered_map<string,vector<pair<string,double>>>& g,set<string>& visited, double& ans, double temp){
        if(visited.find(s)!=visited.end()){
            return;
        }else{
            visited.insert(s);
            if(s==d){
                ans=temp;
                return;
            }else{
                for(auto adj:g[s]){
                    dfs(adj.first,d,g,visited,ans,temp*adj.second);
                }
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>grap;

        for(int i=0;i<equations.size();i++){
            grap[equations[i][0]].push_back({equations[i][1],values[i]});
            grap[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }

        vector<double>result(queries.size());
        for(int i=0;i<queries.size();i++){
            string s=queries[i][0];
            string d=queries[i][1];
            set<string>visited;
            double ans=-1.0;

            if(grap.find(s)!=grap.end()){
                dfs(s,d,grap,visited,ans,1.0);
            }
            result[i]=ans;
        }
        return result;
    }
};