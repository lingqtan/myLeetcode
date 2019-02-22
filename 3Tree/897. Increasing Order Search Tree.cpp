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
    vector<TreeNode*> vec;
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        traverse(root->left);
        vec.push_back(root);
        traverse(root->right);
    }
    void solve() {
        int i = 0;
        for (; i < vec.size()-1; i++) {
            TreeNode* node = vec[i];
            node->left = NULL;
            node->right = vec[i+1];
        }
        vec[i]->left = NULL;
        vec[i]->right = NULL;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        traverse(root);
        TreeNode* head = vec[0];
        solve();
        return head;
    }
};