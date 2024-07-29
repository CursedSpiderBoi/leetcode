// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

 

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Example 2:

// Input: n = 25
// Output: 1389537


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
