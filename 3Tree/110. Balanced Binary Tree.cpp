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
    int abs(int x) {return (x > 0) ? x : -x;}
    bool ans = true;
    int depth(TreeNode* root) {
        if (root == NULL) return -1;
        int l = depth(root->left);
        int r = depth(root->right);
        if (abs(l-r) > 1) ans = false;
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }
};