/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

#include <queue>

vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    if (not root) return ans;
    queue <BinaryTreeNode<int>*> p, s;
    p.push(root);
    while (!p.empty() or !s.empty()) {
        while (!p.empty()) {
            BinaryTreeNode<int> *temp = p.front();
            p.pop();
            if (p.empty()) {
                ans.push_back(temp->data);
            }
            if (temp->left)  s.push(temp->left);
            if (temp->right) s.push(temp->right);
        }
        while (!s.empty()) {
            BinaryTreeNode<int> *temp = s.front();
            s.pop();
            if (s.empty()) {
                ans.push_back(temp->data);
            }
            if (temp->left)  p.push(temp->left);
            if (temp->right) p.push(temp->right);
        }
    }
    return ans;
}
