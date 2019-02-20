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
    vector<string> ans;
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    }
    void dfs(TreeNode* root, string path) {
        if (root == NULL) return;
        if (path != "") {
            path += "->";
        }
        path += to_string(root->val);
        if (isLeaf(root)) {
            ans.push_back(path);
        }
        else {
            dfs(root->left, path);
            dfs(root->right, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) return ans;
        dfs(root, "");
        return ans;
    }
};