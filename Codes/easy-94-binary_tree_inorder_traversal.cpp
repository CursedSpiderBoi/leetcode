// Your are iven the root of a binary tree.

// Return the inorder traversal of its nodes' values.


// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]


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
    void inorderhelp(TreeNode* root, vector<int>& x){
        if(root == NULL){
            return;
        }
        inorderhelp(root->left, x);
        x.push_back(root->val);
        inorderhelp(root->right, x);
    }  
public:  
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> x;
        inorderhelp(root, x);
        return x;
    }
};
