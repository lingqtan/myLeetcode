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
    map<TreeNode*, int> lLongestLen, rLongestLen;
    int ans;
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    }
    void findAllOneSideLongestLen(TreeNode* root) {
        if (root == NULL) return;
        if (isLeaf(root)) {
            lLongestLen[root] = 0, rLongestLen[root] = 0;
            return;
        }
        findAllOneSideLongestLen(root->left);
        findAllOneSideLongestLen(root->right);
        if (root->left == NULL || (root->left)->val != root->val) 
            lLongestLen[root] = 0;
        else {
            lLongestLen[root] = max(lLongestLen[root->left], rLongestLen[root->left]) + 1;
        }
        if (root->right == NULL || (root->right)->val != root->val) 
            rLongestLen[root] = 0;
        else {
            rLongestLen[root] = max(lLongestLen[root->right], rLongestLen[root->right]) + 1;
        }
        ans = max(ans, lLongestLen[root]);
        ans = max(ans, rLongestLen[root]);
        if (root->left && root->right 
            && (root->left)->val == root->val
            && (root->right)->val == root->val)
            ans = max(ans, lLongestLen[root] + rLongestLen[root]);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        ans = 0;
        findAllOneSideLongestLen(root);
        return ans;
    }
};