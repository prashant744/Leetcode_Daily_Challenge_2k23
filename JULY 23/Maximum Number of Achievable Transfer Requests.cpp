class Solution {
public:
    void helper(vector<vector<int>>&req,vector<int>&capacity,int ind,int re,int &maxRequest){
        if(ind>=req.size()){
            for(auto a:capacity){
                if(a!=0)return;
            }
            maxRequest=max(maxRequest,re);
            return;
        }

        helper(req,capacity,ind+1,re,maxRequest);
        capacity[req[ind][0]]--;capacity[req[ind][1]]++;
        helper(req,capacity,ind+1,re+1,maxRequest);
        capacity[req[ind][0]]++;capacity[req[ind][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int maxRequest=0;
        vector<int>capacity(n,0);
        helper(requests,capacity,0,0,maxRequest);
        return maxRequest;
    }
};