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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* node = root;
        bool from_stack = false;
        while (!s.empty() || !from_stack) {
            if (!s.empty() && from_stack) {
                node = s.top();
                s.pop();
                from_stack = true;
            }
            if (!from_stack && node->left) {
                s.push(node);
                node = node->left;
                from_stack = false;
                continue;
            }
            ans.push_back(node->val);
            if (node->right) {
                node = node->right;
                from_stack = false;
                continue;
            }
            from_stack = true;
        }
        return ans;
    }
};