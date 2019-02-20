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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        if (root == NULL) return ans;
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            int n = q.size();
            ans.push_back(vector<int>());
            for (int j = 0; j < n; j++) {
                TreeNode* node = q.front();
                q.pop();
                ans[i].push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            i++;
        }
        for (int j = 0; j < i/2; j++) {
            vector<int> tmp = ans[j];
            ans[j] = ans[i-j-1];
            ans[i-j-1] = tmp;
        }
        return ans;
    }
};