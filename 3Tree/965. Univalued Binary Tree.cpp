/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == NULL) return true;
        if (isUnivalTree(root->left) == false) return false;
        if (isUnivalTree(root->right) == false) return false;
        if (root->left && root->val != (root->left)->val) return false;
        if (root->right && root->val != (root->right)->val) return false;
        return true;
    }
};