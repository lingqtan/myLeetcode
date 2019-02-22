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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            bool findx = false, findy = false;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                if (!findx) findx = node->val == x;
                if (!findy) findy = node->val == y;
                if (node->left && node->right) {
                    if (node->left->val == x && node->right->val == y
                     || node->left->val == y && node->right->val == x)
                        return false;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (findx && findy) return true;
        }
        return false;
    }
};