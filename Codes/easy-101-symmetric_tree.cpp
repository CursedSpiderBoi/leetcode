// You are given the root of a binary tree.

// Check whether it is a mirror of itself (i.e., symmetric around its center, balanced).



// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false



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
    bool isSymmetricHelp(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        if(p->val==q->val)
            return isSymmetricHelp(p->left,q->right)&&isSymmetricHelp(p->right,q->left);
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelp(root->left,root->right);
    }
};
