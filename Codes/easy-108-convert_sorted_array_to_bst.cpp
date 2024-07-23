// Given an integer array nums where the elements are sorted in ascending order, convert it 
// to a height-balanced binary search tree.

 
// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


class Solution {
	TreeNode* Merge(vector<int>& nums, int low,int high){
        if(low<=high){
            int mid = low + (high-low)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = Merge(nums, low, mid-1);
            root->right = Merge(nums, mid+1, high);
            return root;
        }
        return NULL;
    }
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return Merge(nums, 0, nums.size() - 1);
	}
};
