// You are given an unsorted array of integers nums.

// Return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.



// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9


class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0) return 0;
        sort(arr.begin(), arr.end());
        int maxL= 0, cur= 1;
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] == arr[i - 1] + 1)
            {
                cur++;
            }
            else if(arr[i] != arr[i - 1])
            {
                maxL = max(maxL, cur);
                cur = 1;
            }
        }
        
        maxL = max(maxL, cur);
        return maxL;
    }
    };
