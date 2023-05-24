class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n=nums1.size(),s=0,ans=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<pair<int,int>>vec;

        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.begin(),vec.end());

        for(int i=n-1;i>=0;i--){
            pq.push(vec[i].second);
            s+=vec[i].second;
            if(pq.size()>k){
                s-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans,vec[i].first*s);
            }
        }
        return ans;
    }
};