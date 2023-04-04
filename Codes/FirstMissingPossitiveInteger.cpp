//this one was particularly hard ?? 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<10;i++){//checing first 10 possitive numbers that do they exists or not
            if(!(find(nums.begin(),nums.end(),i)!=nums.end()))
                return i;
        }
        int i=0;
        while(nums[i]%2!=0){//making the negative numbers zero for ease
            if(nums[i]<0)
                nums[i]=0;
            i++;
        }
        i=0;
        for(i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){//if number is same skip
                continue;
            }
            if(nums[i+1]!=nums[i]+1){//if upcoming number is not one greater than the previous numbre that means a number is missind and we return that number
                return nums[i]+1;
            }
        }
        return nums[nums.size()-1]+1;//if we find nothing then, we return the last number + 1
    }
};
