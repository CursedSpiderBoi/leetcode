// You are given a binary tree consisting of random integers(nodes).

// Based on the definition, return true if the tree is height-balanced, return false if it is imbalanced.



//Example 1:

//Input: root = [3,9,20,null,null,15,7]
//Output: true

//Example 2:

//Input: root = [1,2,2,3,3,null,null,4,4]
//Output: false

//Example 3:

//Input: root = []
//Output: true



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
