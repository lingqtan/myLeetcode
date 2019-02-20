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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int max_p = 0, max_n = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max_n) {
                max_n = nums[i];
                max_p = i;
            }
        }
        TreeNode* root = new TreeNode(max_n);
        vector<int> lnums, rnums;
        for (int i = 0; i < max_p; i++) lnums.push_back(nums[i]);
        for (int i = max_p+1; i < nums.size(); i++) rnums.push_back(nums[i]);
        root->left = constructMaximumBinaryTree(lnums);
        root->right = constructMaximumBinaryTree(rnums);
        return root;
    }
};