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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<Node*> s;
        unordered_set<Node*> visited;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            if (!node->children.empty() && visited.count(node) == 0) {
                visited.insert(node);
                for (vector<Node*>::reverse_iterator it = node->children.rbegin(); it != node->children.rend(); it++) {
                    s.push(*it);
                }
            }
            else {
                s.pop();
                ans.push_back(node->val);
            }
        }
        
        return ans;
    }
};