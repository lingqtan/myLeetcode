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
    bool isSameSet(vector<int> pre, vector<int> post) {
        if (pre.size() != post.size()) return false;
        sort(pre.begin(), pre.end());
        sort(post.begin(), post.end());
        for (int i = 0; i < pre.size(); i++) {
            if (pre[i] != post[i]) return false;
        }
        return true;
    }
    bool isSameRoot(vector<int> pre, vector<int> post) {
        if (pre.size() == 0 && post.size() == 0) return true;
        if (pre.size() != post.size()) return false;
        return pre[0] == post[post.size()-1];
    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() == 0 || post.size() == 0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        vector<int> lpre, rpre, lpost, rpost;
        int k = 1, n = pre.size();
        while (k <= n) {
            rpre.clear(), rpost.clear();
            for (int i = k; i <= n-1; i++) {
                rpre.push_back(pre[i]);
                rpost.push_back(post[i-1]);
            }
            // if (isSameSet(lpre, lpost) && isSameRoot(lpre, lpost) && isSameRoot(rpre, rpost)) {
            if (isSameRoot(lpre, lpost) && isSameRoot(rpre, rpost)) {
                root->left = constructFromPrePost(lpre, lpost);
                root->right = constructFromPrePost(rpre, rpost);
                break;
            }
            lpre.push_back(pre[k]);
            lpost.push_back(post[k-1]);
            k++;
        }
        return root;
    }
};