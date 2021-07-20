/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
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

***********************************************************/
#include <vector>

vector <BinaryTreeNode<int>*> v;

void f(BinaryTreeNode<int>* root) {
    if (!root) return;
    f(root->left);
    v.push_back(root);
    f(root->right);
}

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    // Write your code here.
    v.clear();
    f(root);
    bool F = false;
    for (auto i: v) {
        if (F) return i;
        if (i->data == node->data) F = true;
    }
    return nullptr;
}
