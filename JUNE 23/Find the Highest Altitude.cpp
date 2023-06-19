class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>altitude;
        int start=0;
        altitude.push_back(start);

        for(int i=0;i<n;i++){
            start=gain[i]+start;
            altitude.push_back(start);
        }

        int ans=*max_element(altitude.begin(),altitude.end());
        return ans;
    }
};