class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>tails,res;
        int size=0;

        for(auto it:obstacles){
            int index=upper_bound(tails.begin(),tails.end(),it)-tails.begin();
            if(index==size){
                tails.push_back(it);
                size++;
            }else{
                tails[index]=it;
            }
            res.push_back(index+1);
        }
        return res;
    }
};