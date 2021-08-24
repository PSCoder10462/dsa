/**********************************************************
    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
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

***********************************************************/
#include <queue>

int getHeight(BinaryTreeNode<int> *root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

BinaryTreeNode<int>* deepestRightLeaf(BinaryTreeNode<int>* root) {
    // Write your code here.
    int h = getHeight(root);

	if (!root) return nullptr;
    queue<BinaryTreeNode<int>*> p, q;
    p.push(root);
    BinaryTreeNode<int> *ans = nullptr;
    int i=1;
	while (!p.empty() or !q.empty()) {
        while (!p.empty()) {
            BinaryTreeNode<int> *temp = p.front();
            p.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) {
                ans = temp->right; q.push(temp->right);
            }
        }
        if (!q.empty()) i++;
        if (i != h) ans = nullptr;
        while (!q.empty()) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            if (temp->left) p.push(temp->left);
            if (temp->right) {
                ans = temp->right; p.push(temp->right);
            }
        }
        if (!p.empty()) i++;
        if (i != h) ans = nullptr;
    }
    return ans;
}
