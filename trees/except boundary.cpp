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

int getLbs(BinaryTreeNode<int> *root) {
    if (!root) return 0;
    if (root->left) return root->data + getLbs(root->left);
    else if (root->right) return root->data + getLbs(root->right);
    return 0;
}

int getRbs(BinaryTreeNode<int> *root) {
    if (!root) return 0;
    if (root->right) return root->data + getRbs(root->right);
    else if (root->left) return root->data + getRbs(root->left);
    return 0;
}

int getLs(BinaryTreeNode<int> *root) {
    if (!root) return 0;
    if (!root->left and !root->right) return root->data;   
    return getLs(root->left)
    	+ getLs(root->right);
}

int getSum(BinaryTreeNode<int> *root) {
    if (!root) return 0;
    return root->data + getSum(root->left) + getSum(root->right);
}

int exceptBoundary(BinaryTreeNode<int> *root) {
    // Write your code here.
    if (!root) return 0;
    // left boundary sum
    int lbs = getLbs(root->left);
    // right boundary sum
    int rbs = getRbs(root->right);
    // leaves sum
    int ls = getLs(root->left) + getLs(root->right);
    // total
    int total = getSum(root);
    
    return total - (lbs+rbs+ls) - root->data;
}
