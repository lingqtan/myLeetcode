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
    
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        int L = solve(root->left);
        int R = solve(root->right);
        ans = max(L+R, ans);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        solve(root);
        return ans;
    }
};