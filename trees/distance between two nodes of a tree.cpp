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

TreeNode<int> *findLCA(TreeNode<int> *root, int n1, int n2) {
    if (!root || root->val == n1 || root->val == n2) 
        return root;
	TreeNode <int>* l = findLCA(root->left, n1, n2);
    TreeNode <int>* r = findLCA(root->right, n1, n2);
    if (l and r) return root;
    return l ? l : r;
}

int findDistance(TreeNode <int> *node, int d, int level = 0) {
    if (!node) return -40000;
    if (node->val == d) return level;
    int l = findDistance(node->left, d, level+1);
    if (l>=0) return l;
    return findDistance(node->right, d, level+1);
}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2)
{
    // Write your code here.
    TreeNode <int>* lca = findLCA(root, node1, node2);
    int l = findDistance(lca, node1);
    int r = findDistance(lca, node2);
    return l+r >= 0 ? l+r : -1;
}
