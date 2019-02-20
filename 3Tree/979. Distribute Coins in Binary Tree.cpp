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
    int abs(int x) {
        return (x > 0) ? x : -x;
    }
    int ans = 0;
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        int x = solve(root->left);
        int y = solve(root->right);
        ans += abs(root->val + x + y - 1);
        return root->val + x + y - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};