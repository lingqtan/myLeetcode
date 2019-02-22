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
    unordered_set<TreeNode*> visited;
    vector<int> ans;
    map<int, int> m;
    
    void solve(TreeNode* root) {
        if (root == NULL) return;
        visited.insert(root);
        if (m.count(root->val) == 0) {
            m[root->val] = 1;
        }
        else {
            m[root->val]++;
        }
        if (root->left && root->left->val == root->val) solve(root->left);
        if (root->right && root->right->val == root->val) solve(root->right);
    }

    void traverse(TreeNode* root) {
        if (root == NULL) return;
        if (visited.count(root) == 0) {
            solve(root);
        }
        traverse(root->left);
        traverse(root->right);
    }
    
    vector<int> output() {
        int max_c = 0;
        for (auto p: m) {
            if (p.second == max_c) {
                ans.push_back(p.first);
            }
            else if (p.second > max_c) {
                max_c = p.second;
                ans.clear();
                ans.push_back(p.first);
            }
        }
        return ans;
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) return ans;
        traverse(root);
        return output();
    }
};