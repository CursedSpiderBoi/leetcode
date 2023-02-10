class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> type;
        for(int i=0;i<nums.size();i++){
             type[nums[i]]++;
             if(type[nums[i]]>1)
                return nums[i];
        }
        return 0;
    }
};
