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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (root == NULL) return ans;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left); 
        }
        return ans;
    }
};