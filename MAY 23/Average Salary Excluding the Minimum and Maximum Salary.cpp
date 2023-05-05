class Solution {
public:
    double average(vector<int>& salary) {
        double dem=0; int mini=INT_MAX; int maxi=0;
        for (int i=0; i<salary.size(); i++){
            dem+= salary[i];
            mini= min(mini,salary[i]); maxi= max(maxi,salary[i]);
        }
        dem-= (maxi+mini);
        dem/= (salary.size()-2);
        return dem;
    }
};