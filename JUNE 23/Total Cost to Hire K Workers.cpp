class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> workers;
        int n=costs.size();
        int i=0,j=n-1;

        while(i<candidates && i<n){
            workers.push({costs[i],i});
            i++;
        }

        while(j>i && j>=n-candidates){
            workers.push({costs[j],j});
            j--;
        }

        long long cost=0;
        while(k--){
            auto [workerCost,index]=workers.top();
            workers.pop();
            cost+=workerCost;

            if(j>=i){
                if(index>j){
                    workers.push({costs[j],j});
                    j--;
                }else{
                    workers.push({costs[i],i});
                    i++;
                }
            }
        }
        return cost;
    }
};