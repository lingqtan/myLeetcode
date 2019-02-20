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
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top(); s.pop();
            ans.push_back(node->val);
            for (vector<Node*>::reverse_iterator it = node->children.rbegin(); it != node->children.rend(); it++) {
                s.push(*it);
            }
        }
        return ans;
    }
};