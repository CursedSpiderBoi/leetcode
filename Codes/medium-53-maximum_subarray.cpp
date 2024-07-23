// Given an integer array nums.

// Find the subarray with the largest sum and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int maxx=nums[0],cur=0;
        for(auto i:nums){
            cur+=i;
            if(cur<0)   cur=0;
            maxx=max(cur,maxx);
        }
        if(maxx==0){
            sort(nums.begin(),nums.end());
            return nums[nums.size()-1];
        }
        return maxx;
    }
};
