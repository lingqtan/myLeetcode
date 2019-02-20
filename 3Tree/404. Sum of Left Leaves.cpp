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
    int ans = 0;
    bool isLeaf(TreeNode* root) {
        return root && !(root->left) && !(root->right);
    }
    void solve(TreeNode* root) {
        if (root == NULL) return;
        if (isLeaf(root->left)) ans += (root->left)->val;
        solve(root->left);
        solve(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return ans;
    }
};