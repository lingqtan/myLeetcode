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
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    }
    vector<vector<int> > ans;
    void solve(TreeNode* root, vector<int>& path, int sum, int target) {
        if (root == NULL) return;
        sum += root->val;
        path.push_back(root->val);
        if (isLeaf(root) && sum == target) {
            ans.push_back(path);
            return;
        }
        if (root->left) {
            solve(root->left, path, sum, target);
            path.pop_back();
        }
        if (root->right) {
            solve(root->right, path, sum, target);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL) return ans;
        vector<int> path;
        solve(root, path, 0, sum);
        return ans;
    }
};