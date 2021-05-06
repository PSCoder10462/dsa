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
#include <algorithm>

std::vector<int> v;

void func(std::queue<TreeNode<int>*>&q) {
    if (q.empty())
        return;
    TreeNode<int>* node = q.front();
    q.pop();
    v.push_back(node->val);
    if (node->left != NULL)
        q.push(node->left);
    if (node->right != NULL)
        q.push(node->right);
    func(q);
}

vector<int> reverseLevelOrder(TreeNode<int> *root)
{
    // Write your code here
    v.clear();
    if (!root) return v;
	std::queue<TreeNode<int>*> q;
    q.push(root);
	func(q);    
	reverse(v.begin(), v.end());
    return v;
}
