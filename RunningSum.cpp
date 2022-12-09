class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(nums[0]);
        int n=0;
        for(int i=1;i<nums.size();i++){
            sum.push_back(sum[i-1]+nums[i]);
        }
        return sum;
    }
};
/*
0ms solution

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 1; i < n; i++)
           nums[i] += nums[i-1];

        return nums;   
    }
};

*/
