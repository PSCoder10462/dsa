/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lcl, rl, ll;

void f(TreeNode<int> *root, int n1, int n2, int l) {
    if (not root) return;
    if (lcl != -1 and rl != -1 and ll != -1) return;
    if (root->val == n1) 
        ll = l; 
    if (root->val == n2) 
        rl = l;
    
    f(root->left, n1, n2, l+1);
    f(root->right, n1, n2, l+1);
    
    if (rl != -1 and ll != -1) 
        lcl = l;
}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    // Write your code here.
    lcl = rl = ll = -1;
    f(root, node1, node2, 0);
    return lcl == -1 ? -1 : (rl - lcl) + (ll - lcl);
}
