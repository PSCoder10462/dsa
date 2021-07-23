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

#include <algorithm>
#include <unordered_map>

std::unordered_map <TreeNode<int>*, int> mp;

int getHeight(TreeNode <int> *root) {
    if (not root) return 0;
    if (mp[root]) return mp[root];
    int lh, rh;
    if (!mp[root->left]) {
    	lh = getHeight(root->left);
        mp[root->left] = lh;
    } else
        lh = mp[root];
    if (!mp[root->right]) {
    	rh = getHeight(root->right);
        mp[root->right] = rh;
    } else
        lh = mp[root];
    return 1+std::max(lh, rh);
}

int f(TreeNode <int> *root) {
    if (not root) return 0;
	// Write Your Code Here.
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    
    int rd = lh+rh;
    int ans = std::max(rd, f(root->left));
    ans = std::max(ans, f(root->right));
   	return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    mp.clear();
	return f(root);
}
