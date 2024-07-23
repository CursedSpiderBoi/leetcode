// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// You are given an integer n.

// Return true if n is an ugly number; otherwise, return false.

 

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3

// Example 2:

// Input: n = 1
// Output: true
// Explanation: 1 has no prime factors. Therefore, all of its prime factors are limited to 2, 3, and 5.

// Example 3:

// Input: n = 14
// Output: false
// Explanation: 14 is not ugly since it includes the prime factor 7.


bool isUgly(int n) {
        if(n==0) return false;
        while(n%5==0) n/=5;
        while(n%3==0) n/=3;
        while(n%2==0) n/=2;
        if(n==1) return true;
        else return false;
    }
