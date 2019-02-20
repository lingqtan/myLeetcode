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
    string ans;
    void solve(TreeNode* t) {
        if (t == NULL) return;
        ans += to_string(t->val);
        if ((t->left) && (t->right)) {
            ans += "(";
            solve(t->left);
            ans += ")(";
            solve(t->right);
            ans += ")";
        }
        else if (!(t->left) && (t->right)) {
            ans += "()(";
            solve(t->right);
            ans += ")";           
        }
        else if ((t->left) && !(t->right)) {
            ans += "(";
            solve(t->left);
            ans += ")";
        }
        else return;        
    }
public:
    string tree2str(TreeNode* t) {
        solve(t);
        return ans;
    }
};