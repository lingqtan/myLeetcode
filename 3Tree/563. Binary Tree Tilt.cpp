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
    int abs(int x, int y) {
        if (x > y) return x - y;
        else return y - x;
    }
    int ans = 0;
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        ans += abs(l, r);
        return root->val + l + r;
    }
public:
    int findTilt(TreeNode* root) {
        solve(root);
        return ans;
    }
};