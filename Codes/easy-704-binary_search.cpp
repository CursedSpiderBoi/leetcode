class Solution {

/**
* Given an array of integers, which is sorted in ascending order, and an integer target, 
* The function searches the target in the array. If the target exists, return its index. Otherwise, return -1.
* The algorithm operates in O(log n) runtime complexity.
*
* @param v Array of ascending order integers
* @param k The target integer
*/

public:
    int search(vector<int>& v, int k) {
        int i =0,j=v.size()-1,mid;
        while(i<=j){
            mid = (j-i)/2+i;
            if(v[mid]>k)
                j = mid-1;
            else if(v[mid]<k)
                i = mid+1;
            else return mid;
        }
        return -1;
    }
};
