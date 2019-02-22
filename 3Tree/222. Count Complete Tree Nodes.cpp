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
    bool check(TreeNode* root, int n) {
        int bit[32];
        int i = -1;
        while (n > 1) {
            bit[++i] = n % 2;
            n >>= 1;
        }
        TreeNode* curr = root;
        for (int j = i; j >= 0; j-- ) {
            if (!curr) return false;
            if (bit[j] == 0) curr = curr->left;
            else curr = curr->right;
        }
        return (curr != NULL);
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int s = 1;
        TreeNode* curr = root;
        while (curr->left) { 
            s <<= 1;
            curr = curr->left;
        }
        int t = (s << 1) - 1;
        if (check(root, t)) return t;
        int mid = (s+t) >> 1;
        while (t - s > 1) {
            if (check(root, mid)) s = mid;
            else t = mid;
            mid = (s+t) >> 1;
        }
        return s;
    }
};