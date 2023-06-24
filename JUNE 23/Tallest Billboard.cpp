class Solution {
public:
    int helper(int i,vector<int>&v,int a,int b){
        if(i==v.size()){
            if(a==b){
                return a;
            }
            return 0;
        }
        
        int x=helper(i+1,v,a,b);
        int y=helper(i+1,v,a+v[i],b);
        int z=helper(i+1,v,a,b+v[i]);

        return max({x,y,z});
    }

    int tallestBillboard(vector<int>& rods) {
        return helper(0,rods,0,0);
    }
};