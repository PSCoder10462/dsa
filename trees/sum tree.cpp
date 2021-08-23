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

BinaryTreeNode<int> *changeTree(BinaryTreeNode<int> *root) {
    if (!root) return nullptr;
    
    int sum = 0;
    
    if (root->left) sum += root->left->data;
    if (root->right) sum += root->right->data;
    
    root->data = sum;
    
    root->left = changeTree(root->left);
    root->right = changeTree(root->right);
    
    return root;
}

void getPreOrder(BinaryTreeNode<int> *root, vector<int> &ans) {
    if (!root) return;
    
    ans.push_back(root->data);
    
    getPreOrder(root->left, ans);
    getPreOrder(root->right, ans);
}

vector<int> sumTree(BinaryTreeNode<int> *root)
{
    //Write your code here
	  root = changeTree(root);
    
    vector<int> ans;
    getPreOrder(root, ans);
    
    return ans;
}
