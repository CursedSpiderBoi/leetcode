// You are given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return the repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2

// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3

// Example 3:

// Input: nums = [3,3,3,3,3]
// Output: 3
 

class Solution {
public:
    //floyd cycle detection
    int findDuplicate(vector<int>& costs) {
        int i=0,j=0;
        while(true){
            i=costs[i];
            j=costs[costs[j]];
            if(i==j)
                break;
        }
        j=0;
        while(true){
            i=costs[i];
            j=costs[j];
            if(i==j)
                return i;
        }
        return j;
    }
};
