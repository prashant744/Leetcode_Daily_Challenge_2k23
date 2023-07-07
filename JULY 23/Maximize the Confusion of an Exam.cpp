class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int start=0,end=0;
        int t=0,f=0;
        int ans=0;

        while(end<n){
            t+=(answerKey[end]=='T');
            f+=(answerKey[end]=='F');

            while(t>k && f>k){
                if(answerKey[start]=='T'){
                    t--;
                }else{
                    f--;
                }
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};