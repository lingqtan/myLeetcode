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
    string smallestFromLeaf(TreeNode* root) {
        if (root == NULL) return "";
        string s1 = smallestFromLeaf(root->left);
        string s2 = smallestFromLeaf(root->right);
        string s;
        if (s1 == "" && s2 != "") s = s2;
        else if (s1 != "" && s2 == "") s = s1;
        else s = min(s1, s2);
        return s + (char)(root->val + 'a');
    }
};