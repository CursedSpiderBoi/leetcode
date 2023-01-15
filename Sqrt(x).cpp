class Solution {
public:
    int mySqrt(int x) {
        long long l=1;
        long long h=x;
        int res=0;
        while(l<=h){
            long long  mid=(l+h)/2;
            if(mid*mid==x){
                return mid;
            }
            else if((mid*mid)<x){
                l=mid+1;
                res=mid;
            }
            else {
                h=mid-1;
            }
        }
        return res;
    }
};
