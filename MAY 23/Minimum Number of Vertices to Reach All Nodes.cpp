class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,list<int>>adj;
        vector<int>temp(n,0),ans;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            temp[i[1]]++;
        }
        for(int i=0;i<n;i++){
            if(temp[i]==0)ans.push_back(i);
        }
        return ans;
    }
};