class Solution {
public:
    int ans=INT_MAX;

    void helper(int start,vector<int>&nums,vector<int>&vec,int k){
        if(start==nums.size()){
            int maximum=INT_MIN;
            for(int i=0;i<k;i++){
                maximum=max(maximum,vec[i]);
            }
            ans=min(ans,maximum);
            return;
        }

        for(int i=0;i<k;i++){
            vec[i]+=nums[start];
            helper(start+1,nums,vec,k);
            vec[i]-=nums[start];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size();
        vector<int>vec(k,0);
        helper(0,cookies,vec,k);
        return ans;
    }
};