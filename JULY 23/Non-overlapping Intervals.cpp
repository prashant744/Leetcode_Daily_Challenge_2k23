bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int low=0,high=1;

        while(high<intervals.size()){
            if(intervals[low][1]>intervals[high][0]){
                cnt++;high++;
            }else{
                high++;low=high-1;
            }
        }
        return cnt;
    }
};