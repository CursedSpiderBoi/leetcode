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
