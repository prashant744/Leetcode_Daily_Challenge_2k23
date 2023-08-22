
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string XL= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n=columnNumber;
        string ans="";
        while(n>0){
            n-=1;
            int k=n%26;
            ans.push_back(XL[k]);
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};