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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        bool zigzag = false;
        while (!q.empty()) {
            int n = q.size();
            level.clear();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (zigzag) reverse(level.begin(), level.end());
            ans.push_back(level);
            zigzag = !zigzag;
        }
        return ans;
    }
};