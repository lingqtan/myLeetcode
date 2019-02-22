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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        int x = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(x);
        vector<int> lin, lpost, rin, rpost;
        int p = 0;
        for (int i = 0; i < inorder.size(); i++) if (x == inorder[i]) {
            p = i; break;
        }
        for (int i = 0; i < p; i++) {
            lin.push_back(inorder[i]);
            lpost.push_back(postorder[i]);
        }
        for (int i = p+1; i < inorder.size(); i++) {
            rin.push_back(inorder[i]);
            rpost.push_back(postorder[i-1]);
        }
        root->left = buildTree(lin, lpost);
        root->right = buildTree(rin, rpost);
        return root;
    }
};