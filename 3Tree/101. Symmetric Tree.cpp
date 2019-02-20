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
    bool answer(TreeNode* p1, TreeNode* p2) {
        if (p1 == NULL && p2 == NULL) return true;
        if (p1 == NULL || p2 == NULL) return false;
        if (p1->val != p2->val) return false;
        return answer(p1->left, p2->right) && answer(p1->right, p2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* p1 = root;
        TreeNode* p2 = root;
        return answer(p1, p2);
    }
};