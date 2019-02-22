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
    void del(TreeNode* root) {
        if (root == NULL) return;
        del(root->left);
        del(root->right);
        delete root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) return NULL;
        TreeNode* lt = root->left;
        TreeNode* rt = root->right;
        if (root->val > R) {
            // del(root->right);
            // delete root;
            return trimBST(lt, L, R);
        }
        else if (root->val < L) {
            // del(root->left);
            // delete root;
            return trimBST(rt, L, R);
        }
        else {
            root->left = trimBST(lt, L, R);
            root->right = trimBST(rt, L, R);
            return root;
        }
    }
};