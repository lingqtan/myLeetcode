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
    map<TreeNode*, int> m;
    int ans;

    void solve(TreeNode* node, TreeNode* prev) {
        if (node == NULL) return;
        int c = 0;
        if (prev != NULL && m.count(prev) != 0) {
            c = m[prev];
        } 
        if (m.count(node) == 0) {
            m[node] = c * 10 + node->val;
        }
        if (isLeaf(node)) ans += m[node];
        solve(node->left, node);
        solve(node->right, node);
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        ans = 0;
        solve(root, NULL);
        return ans;
    }
};