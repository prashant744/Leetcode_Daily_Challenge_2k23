class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a || b || c){
            if(c&1){
                if(!(a&1) && !(b&1)){
                    ans++;
                }
            }else{
                if((a&1) || (b&1)){
                    ans+=2;
                }else if((a&1) || (b&1)){
                    ans+=1;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return ans;
    }
};