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
    vector<vector<int> > ans;
    map<TreeNode*, pair<int, int> > m;
    typedef pair<int, pair<int, int> > TRIPLE;
    vector<TRIPLE> v;

    static bool cmp(const TRIPLE& t1, const TRIPLE& t2) {
        if (t1.second.first < t2.second.first) return true;
        if (t1.second.first > t2.second.first) return false;
        if (t1.second.second < t2.second.second) return true;
        if (t1.second.second > t2.second.second) return false;
        return t1.first < t2.first;
    }
    
    void traverse(TreeNode* root) {
        if (root == NULL) return;
        int x = m[root].first;
        int y = m[root].second;
        if (root->left) {
            m[root->left] = pair(x-1, y+1);
            traverse(root->left);
        }
        if (root->right) {
            m[root->right] = pair(x+1, y+1);
            traverse(root->right);
        }
    }
    
    void map2vec() {
        for (auto elem: m) {
            v.push_back(pair(elem.first->val, elem.second));
        }
        sort(v.begin(), v.end(), cmp);
    }
    
    void solve() {
        int x = -1000;
        vector<int> req;
        for (auto elem: v) {
            int x1 = elem.second.first;
            if (x != x1) {
                if (req.size() != 0) ans.push_back(req);
                x = x1;
                req.clear();
            }
            req.push_back(elem.first);
        }
        ans.push_back(req);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return ans;
        m[root] = pair(0, 0);
        traverse(root);
        map2vec();
        solve();
        return ans;
    }
};