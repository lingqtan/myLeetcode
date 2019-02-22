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
    int ans;
    void solve(TreeNode* root) {
        if (root == NULL) return;
        if (root->left && root->right) {
            if (root->val == root->left->val) solve(root->left);
            if (root->val == root->right->val) solve(root->right);
            
            int y = root->val ^ root->left->val ^ root->right->val;
            if (y != root->val) {
                ans = (ans == -1) ? y : min(y, ans);
            }
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) return 0;
        ans = -1;
        solve(root);
        return ans;
    }
};