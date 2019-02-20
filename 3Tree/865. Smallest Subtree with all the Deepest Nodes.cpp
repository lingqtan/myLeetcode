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
    vector<vector<TreeNode*> > paths;
    
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    void findPaths(TreeNode* root, vector<TreeNode*>& path, int n) {
        path.push_back(root);
        if (path.size() == n) {
            vector<TreeNode*> v;
            for (int i = 0; i < path.size(); i++) {
                v.push_back(path[i]);
            }
            paths.push_back(v);
            return;
        }
        if (root->left) {
            findPaths(root->left, path, n);
            path.pop_back();
        }
        if (root->right) {
            findPaths(root->right, path, n);
            path.pop_back();
        } 
    }
    
    TreeNode* findLCA() {
        if (paths.size() == 0) return NULL;
        if (paths.size() == 1) return paths[0][paths[0].size()-1];
        TreeNode* ans = NULL;
        for (int i = 1; i < paths[0].size(); i++) {
            ans = paths[0][i-1];
            bool update = true;
            for (int j = 1; j < paths.size(); j++) {
                if (paths[0][i]->val != paths[j][i]->val) {
                    update = false;
                    break;
                }
            }
            if (!update) break;
        }
        return ans;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) return NULL;
        int n = depth(root);
        vector<TreeNode*> path;
        findPaths(root, path, n);
        return findLCA();
    }
};