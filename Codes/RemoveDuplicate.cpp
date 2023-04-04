class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int pos = 0;
    for (auto x : nums)
        {if(pos==0) nums[pos++] = x;
            else  
            if( x > nums[pos-1])
                nums[pos++] = x;}
        return pos;
    }
};
