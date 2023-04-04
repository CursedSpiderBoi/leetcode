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
