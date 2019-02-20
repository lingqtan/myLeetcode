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
    map<TreeNode*, int> node_sum;
    bool isLeaf(TreeNode* root) {
        return root && root->left == NULL && root->right == NULL;
    }
    int solve(TreeNode* root) {
        if (root == NULL) return 0;
        if (node_sum.count(root) == 0) {
            if (isLeaf(root)) {
                node_sum[root] = root->val;
            }
            else {
                int x = solve(root->left);
                int y = solve(root->right);
                node_sum[root] = root->val + x + y;                
            }
        }
        return node_sum[root];
    }
    
    vector<int> output() {
        map<int, int> count;
        map<TreeNode*, int>::iterator it;
        int max_c = 0;
        for (it = node_sum.begin(); it != node_sum.end(); it++) {
            if (count.count(it->second) == 0) count[it->second] = 0;
            count[it->second]++;
            max_c = max(max_c, count[it->second]);
        }
        vector<int> ans;
        for (auto c: count) {
            if (c.second == max_c)
                ans.push_back(c.first);
        }
        return ans;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        return output();
    }
};