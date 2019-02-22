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
    TreeNode* make(int s, int t, vector<int>& nums) {
        if (s > t) return NULL;
        if (s == t) return new TreeNode(nums[s]);
        int mid = (s + t) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = make(s, mid-1, nums);
        root->right = make(mid+1, t, nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return make(0, nums.size()-1, nums);
    }
};