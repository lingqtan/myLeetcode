/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int> > ans;
        if (root == NULL) return ans;
        vector<Node*> _children;
        Node* sepNode = new Node(-1, _children);
        q.push(root); q.push(sepNode);
        int i = 0;
        ans.push_back(std::vector<int>());
        while (q.size() > 1) {
            Node* node = q.front();
            q.pop();
            vector<int>& row = ans[i];
            if (node->val == -1) {
                ans.push_back(std::vector<int>());
                i++;
                q.push(sepNode);
                continue;
            }
            row.push_back(node->val);
            for (auto child: node->children) {
                q.push(child);
            }
        }
        return ans;
    }
};