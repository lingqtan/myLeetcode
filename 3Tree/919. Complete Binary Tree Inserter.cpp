/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    TreeNode* root = NULL;
    int n = 0;
    
    void measureSize() {
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            this->n += q.size();
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        measureSize();
    }
    
    int insert(int v) {
        (this->n)++;
        int bit[32];
        int k = 0, i = this->n;
        while (i) {
            bit[k++] = i % 2;
            i /= 2;
        }
        k -= 1;
        TreeNode* node = this->root;
        for (i = k-1; i >= 1; i--) {
            node = (bit[i]) ? node->right : node->left;
        }
        TreeNode* newNode = new TreeNode(v);
        if (bit[0]) node->right = newNode;
        else node->left = newNode;
        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */