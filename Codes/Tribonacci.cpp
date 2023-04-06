class Solution {
public:
    int tribonacci(int n) {
        switch(n){
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 1;
            default:
                goto start;          
        }
        start:
        int a=0,b=1,c=1;
        for(int i=2,k=0;i<n;i++){
            if(k==0){
                a=a+b+c;
                k++;
                continue;
            }
            if(k==1){
                b=a+b+c;
                k++;
                continue;
            }
            if(k==2){
                c=a+b+c;
                k=0;
                continue;
            }
        }
        return max(max(a,b),c);
    }
};
