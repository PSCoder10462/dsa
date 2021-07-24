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

#include <utility>

pair<int, int> hd(TreeNode<int> *root) {
    pair<int, int> ans;
    ans.first = 0;
    ans.second = 0;
    if (not root) return ans;
    auto tl = hd(root->left), tr = hd(root->right);
    ans.first = 1+std::max(tl.first, tr.first);
    ans.second = std::max(tl.second, std::max(tr.second, tl.first+tr.first));
	return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    auto ans = hd(root);
    return ans.second;
}
