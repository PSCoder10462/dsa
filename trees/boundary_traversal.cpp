/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <algorithm>

std::vector<int> v, leafb, leftb, rightb;

void leftBoundary(TreeNode<int>* root) {
    // check for empty tree and leaf node
    if (!root || (!root->right && !root->left)) return;
    
    leftb.push_back(root->data);
    
    leftBoundary(root->left);
    
    if (!root->left)
        leftBoundary(root->right);
}

void leafBoundary(TreeNode<int>* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        leafb.push_back(root->data);
        return;
    }
    leafBoundary(root->left);
    leafBoundary(root->right);
}

void rightBoundary(TreeNode<int>* root) {
    // check for empty tree and leaf node
    if (!root || (!root->right && !root->left)) return;
    
    rightb.push_back(root->data);
    
	rightBoundary(root->right);
    if (!root->right)
        rightBoundary(root->left);
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    v.clear();
    leftb.clear();
    rightb.clear();
    // Write your code here
    if (!root) return v;
    
    v.push_back(root->data);
    
    leftBoundary(root->left);
    v.insert(v.end(), leftb.begin(), leftb.end());
	
    leafb.clear();
    leafBoundary(root->left);
    v.insert(v.end(), leafb.begin(), leafb.end());
    
    leafb.clear();
    leafBoundary(root->right);
    v.insert(v.end(), leafb.begin(), leafb.end());
    
    
    rightBoundary(root->right);
    reverse(rightb.begin(), rightb.end());
    v.insert(v.end(), rightb.begin(), rightb.end());
    
    return v;
}
