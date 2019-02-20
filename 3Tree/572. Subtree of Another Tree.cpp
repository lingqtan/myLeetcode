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
    bool ans = false;
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val != t->val) return false;
        else return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    void solve(TreeNode* s, TreeNode* t) {
        if (ans || s == NULL) return;
        ans = isSameTree(s, t);
        solve(s->left, t);
        solve(s->right, t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (t == NULL) return true;
        if (s == NULL) return false;
        solve(s, t);
        return ans;
    }
};