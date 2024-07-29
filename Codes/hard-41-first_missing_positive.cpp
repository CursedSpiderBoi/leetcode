// You are given an unsorted integer array nums. 

// Return the smallest positive integer that is not present in nums.

// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.

// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.

    
class Solution {
public:
    //this one was particularly hard ?? 
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<10;i++){  //checking first 10 positive numbers that do they exist or not
            if(!(find(nums.begin(),nums.end(),i)!=nums.end()))
                return i;
        }
        int i=0;
        while(nums[i]%2!=0){  //making the negative numbers zero for ease
            if(nums[i]<0)
                nums[i]=0;
            i++;
        }
        i=0;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){  //if number is same skip
                continue;
            }
            if(nums[i+1]!=nums[i]+1){  //if upcoming number is not one greater than the previous number that means a number is missing and we return that number
                return nums[i]+1;
            }
        }
        return nums[nums.size()-1]+1;  //if we find nothing then, we return the last number + 1
    }
};
