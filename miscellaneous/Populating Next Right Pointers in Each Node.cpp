/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> p, q;
        if (root)
            p.push(root);
        while (!p.empty() or !q.empty()) {
            while (!p.empty()) {
                auto t = p.front();
                p.pop();
                if (!p.empty())
                    t->next = p.front();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                if (!q.empty())
                    t->next = q.front();
                if (t->left)
                    p.push(t->left);
                if (t->right)
                    p.push(t->right);
            }
        }
        return root;
    }
};
