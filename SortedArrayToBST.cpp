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
