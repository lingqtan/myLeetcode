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
    vector<int> leaves1, leaves2;
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    } 
    void traverse(TreeNode* root, int k) {
        if (root == NULL) return;
        traverse(root->left, k);
        traverse(root->right, k);
        if (isLeaf(root)) {
            if (k == 1) leaves1.push_back(root->val);
            else leaves2.push_back(root->val);
            return;
        }  
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leaves1.clear(), leaves2.clear();
        traverse(root1, 1);
        traverse(root2, 2);
        if (leaves1.size() != leaves2.size()) return false;
        for (int i = 0; i < leaves1.size(); i++) {
            if (leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
};