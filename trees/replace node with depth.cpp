
/*************************************************************
 
    Following is the Binary Tree node structure.

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
BinaryTreeNode<int> *func(BinaryTreeNode<int> *root, int depth) {
    if (!root) return root;
    root->data = depth;
    root->left = func(root->left, depth+1);
    root->right = func(root->right, depth+1);
    return root;
}

BinaryTreeNode<int> *changeToDepthTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    root = func(root, 0);
    return root;
}
