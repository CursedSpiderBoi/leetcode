/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/** 
* When given a binary tree, based on the definition, determine if it is 'height-balanced'
* @param root The root node of the tree
*/

class Solution {    
	int Height(TreeNode* root) {
		if (root == NULL) 
            return 0;
		int leftHeight = Height(root->left);
		int rightHight = Height(root->right);
		if (leftHeight==-1||rightHight==-1||abs(leftHeight - rightHight)>1)
            return -1;
		return max(leftHeight, rightHight) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)  return true;
		if (Height(root) == -1)  return false;
		return true;
	}
};
