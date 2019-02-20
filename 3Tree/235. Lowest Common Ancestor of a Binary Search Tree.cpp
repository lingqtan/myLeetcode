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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (root == NULL || root == p || root == q) return root;
        // TreeNode* l = lowestCommonAncestor(root->left, p, q);
        // TreeNode* r = lowestCommonAncestor(root->right, p, q);
        // if (l && r) return root;
        // if (l) return l;
        // if (r) return r;
        // return NULL;
        
        if (root == NULL || root == p || root == q) return root;
        bool L = root->val >= p->val && root->val >= q->val;
        bool R = root->val < p->val && root->val < q->val;
        if (L) return lowestCommonAncestor(root->left, p, q);
        if (R) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};