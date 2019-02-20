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
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    }
    void solve(TreeNode* root, int& sum, int target) {
        if (ans) return;
        if (root == NULL) return;
        sum += root->val;
        if (isLeaf(root)) {
            if (sum == target) ans = true;
            sum -= root->val;
            return;
        }
        solve(root->left, sum, target);
        solve(root->right, sum, target);
        sum -= root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        int currSum = 0;
        solve(root, currSum, sum);
        return ans;
    }
};