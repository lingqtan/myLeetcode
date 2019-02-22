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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return NULL;
        int x = preorder[0];
        TreeNode* root = new TreeNode(x);
        vector<int> lin, lpre, rin, rpre;
        int p = 0;
        for (int i = 0; i < inorder.size(); i++) if (x == inorder[i]) {
            p = i; break;
        }
        for (int i = 0; i < p; i++) {
            lin.push_back(inorder[i]);
            lpre.push_back(preorder[i+1]);
        }
        for (int i = p+1; i < inorder.size(); i++) {
            rin.push_back(inorder[i]);
            rpre.push_back(preorder[i]);
        }
        root->left = buildTree(lpre, lin);
        root->right = buildTree(rpre, rin);
        return root;
    }
};