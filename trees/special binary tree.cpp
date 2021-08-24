  /*************************************************************

    Following is the Binary Tree node structure

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

bool isSpecialBinaryTree(BinaryTreeNode<int>* root)
{
    // Write your code here.
    if (!root) return true;
    
    if ((!root->left and root->right) or (root->left and !root->right)) return false;
    
    if (!root->left and !root->right) return true;
    
    return isSpecialBinaryTree(root->left) and isSpecialBinaryTree(root->right);
}
