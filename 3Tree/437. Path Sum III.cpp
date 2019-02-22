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
    int ans;
    void traverse(TreeNode* root, int& target) {
        if (root == NULL) return;
        int sum = 0;
        solve(root, sum, target);
        traverse(root->left, target);
        traverse(root->right, target);
    }
    
    void solve(TreeNode* root, int& sum, int& target) {
        if (root == NULL) return;
        sum += root->val;
        if (sum == target) ans++;
        solve(root->left, sum, target);
        solve(root->right, sum, target);
        sum -= root->val;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        traverse(root, sum);
        return ans;
    }
};