/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    Node* check (int n, Node* root) {
        if (root == NULL) return NULL;
        int bit[32];
        int i = -1;
        while (n > 1) {
            bit[++i] = n % 2;
            n >>= 1;
        }
        Node* curr = root;
        for (int j = i; j >= 0; j--) {
            if (curr == NULL) return NULL;
            if (bit[j] == 0) curr = curr->left;
            else curr = curr->right;
        }
        return curr;
    }
    
    int depth(Node* root) {
        if (root == NULL) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        int D = depth(root);
        for (int d = 1; d <= D; d++) {
            int s = 1 << (d-1), t = (1 << d) - 1;
            Node* prev = NULL;
            while (s <= t) {
                Node* node = check(s, root);
                if (node) {
                    if (prev) prev->next = node;
                    prev = node;
                }
                s++;
            }
        }
        return root;
    }
};