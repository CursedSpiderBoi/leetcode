// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

// You are given a binary string 's'. 

// You can flip s[i] changing it from 0 to 1 or from 1 to 0.

// Return the minimum number of flips to make 's' monotone increasing.



// Example 1:

// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
    
// Example 2:

// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.

// Example 3:

// Input: s = "00011000"
// Output: 2
// Explanation: We flip to get 00000000.


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0;
        int ones=0;
        for(auto i=0;s[i]; i++){
            if(s[i]=='1')
                ones++;
            else if( ones>0){
                flips++;
                ones--;
            }
        }
        return flips;
    }
};
