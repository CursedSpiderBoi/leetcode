//fibonacci sequence
class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1;
        for(int i=0,temp=0;i<n;i++){
            temp=a;
            a=b;
            b=temp+b;
        }
        return b;
    }
};
