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

bool checkTree(BinaryTreeNode<int> *tree1, BinaryTreeNode<int> *tree2) 
{
    // Write your code here.
    if (!tree1 and !tree2) return true;
    if ((tree1 and !tree2) or (tree2 and !tree1)) return false;
    if (tree1->data != tree2->data) return false;
  	
    return (checkTree(tree1->left, tree2->left) and checkTree(tree1->right, tree2->right))
        or
        (checkTree(tree1->right, tree2->left) and checkTree(tree1->left, tree2->right));
}
