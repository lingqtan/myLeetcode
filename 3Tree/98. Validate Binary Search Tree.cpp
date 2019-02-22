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
    bool ans;
    
    void scan(int x, TreeNode* root, char cmp) {
        if (!ans) return;
        if (root == NULL) return;
        if (cmp == '<') ans = root->val < x;
        else ans = root->val > x;
        if (ans) scan(x, root->left, cmp);
        if (ans) scan(x, root->right, cmp);
    }
    
    void valid(TreeNode* root) {
        if (!ans) return;
        if (root == NULL) return;
        int x = root->val;
        scan(x, root->left, '<');
        if (ans) scan(x, root->right, '>');
    }
    
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        if (ans) valid(root);
        if (ans) traverse(root->left);
        if (ans) traverse(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        ans = true;
        traverse(root);
        return ans;
    }
};