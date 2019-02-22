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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == n-1) {
                    ans.push_back(node->val);
                }
            }
        }
        return ans;
    }
};