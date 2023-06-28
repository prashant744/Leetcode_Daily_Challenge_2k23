class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>to(n);
        for(int i=0;i<edges.size();i++){
            to[edges[i][0]].emplace_back(edges[i][1],succProb[i]);
            to[edges[i][1]].emplace_back(edges[i][0],succProb[i]);
        }
        vector<double>prob(n,0);
        queue<int>Q;
        Q.push(start);
        prob[start]=1;

        while(!Q.empty()){
            int node=Q.front();
            Q.pop();
            for(auto child:to[node]){
                int nxt=child.first;
                double p=child.second;
                if(prob[nxt] < prob[node]*p){
                    prob[nxt]=prob[node]*p,Q.push(nxt);
                }
            }
        }
        return prob[end];
    }
};