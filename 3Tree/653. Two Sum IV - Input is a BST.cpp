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
    bool ans = false;
    TreeNode* Root;
    bool findx(TreeNode* root, int x) {
        if (root == NULL) return false;
        if (root->val == x) return true;
        if (root->val > x) return findx(root->left, x);
        else return findx(root->right, x);
    }
    void solve(TreeNode* root, int k) {
        if (root == NULL || ans) return;
        int x = k - root->val;
        if (x != root->val && findx(Root, x)) {
            ans = true;
            return;
        }
        solve(root->left, k);
        solve(root->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        Root = root;
        solve(root, k);
        return ans;
    }
};