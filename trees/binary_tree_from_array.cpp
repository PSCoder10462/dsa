
/*********************************************
   Following is the Tree Node structure 
 
template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val) {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

**********************************************/
TreeNode <int>* createNode(int value) {
    if (value == -1) return NULL;
    TreeNode<int> *node = new TreeNode<int> (value);
    node->left = node->right=NULL;
    return node;
}


TreeNode <int>* constructCBT(vector <int> arr) {
	// Write your code here
    if (arr.size() < 1) return NULL;
    
    std::queue<TreeNode <int>*> q;
    
    TreeNode <int>* root = createNode(arr[0]);
    q.push(root);
    for (int i=1; i<arr.size(); ++i) {
        TreeNode <int>* node = q.front();
        q.pop();
        node->left = createNode(arr[i]);
        if (i < arr.size()-1) {
            node->right = createNode(arr[i+1]); 
            ++i;
        }
        else node->right = NULL;
        q.push(node->left);
        q.push(node->right);
    }
    return root;
}
