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
    bool is_bottom_right_most;
    void solve(TreeNode* root, int& sum) {
        if (root == NULL) return;
        solve(root->right, sum);
        if (is_bottom_right_most) {
            sum = root->val;
            is_bottom_right_most = false;
        }
        else {
            int k = root->val;
            root->val += sum;  
            sum += k;
        }
        solve(root->left, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        is_bottom_right_most = true;
        int sum = 0;
        solve(root, sum);
        return root;
    }
};