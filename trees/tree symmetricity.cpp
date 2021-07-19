/*
    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };
*/

bool func(BinaryTreeNode<int> *l, BinaryTreeNode<int> *r) {
    if (!l and !r) return true;
    if (!l or !r) return false;
    if (r->data != l->data) return false;
    return func(l->right, r->left) and func(l->left, r->right);
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    if (!root) return true;
    return func(root->left, root->right);
}
