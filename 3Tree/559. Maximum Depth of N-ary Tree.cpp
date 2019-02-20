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
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        int t_max = 0;
        for (auto child: root->children) {
            t_max = max(maxDepth(child), t_max);
        }
        return t_max+1;
    }
};