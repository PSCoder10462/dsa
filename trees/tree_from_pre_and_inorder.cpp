/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <unordered_map>

// storing index of inorder for ease of search(reducing time complexity)
unordered_map<int, int> m;
int index = 0;

TreeNode<int> *createNode(int value) {
    TreeNode<int> *root = new TreeNode<int> (value);
    return root;
}

TreeNode<int> *func(int lb, int ub, vector<int> &preorder, vector<int> &inorder) {
    
    // corner case safety
    if (lb > ub) return NULL;
    
    // creating value with current node
    TreeNode<int> *res = createNode(preorder[index++]);
    
    // leaf node condition
    if (lb == ub) return res;
    
    // search in inorder vector
    int in = m[res -> data];
    
    // data to left subtree
    res -> left = func(lb, in-1, preorder, inorder);
    
    // data to right sub tree
    res -> right = func(in+1, ub, preorder, inorder);
    
    // return response
    return res;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here    
    if (inorder.size()==0) return NULL;
    
    m.clear();
    index = 0;
    
    for (int i=0; i<inorder.size(); ++i)
        m[inorder[i]] = i;

	return func(0, preorder.size()-1, preorder, inorder);

}
