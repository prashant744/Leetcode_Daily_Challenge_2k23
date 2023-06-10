class Solution {
public:
    long sum(long n){
        return (n*(n+1))/2;
    }

    int maxValue(int n, int index, int maxSum) {
        long left=1,right=maxSum;
        long i=index,j=n-index-1;
        long result=0;

        while(left<=right){
            long mid=(right+left)/2;
            long m=mid-1;
            long ls=i>=m?(sum(m)+i-m):(sum(m)-sum(m-i));
            long rs=j>=m?(sum(m)+j-m):(sum(m)-sum(m-j));

            if(ls+rs+mid<=maxSum){
                result=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return result;
    }
};