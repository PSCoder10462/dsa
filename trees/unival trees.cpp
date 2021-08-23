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

#include <bits/stdc++.h>
#define mp make_pair

// returns if unival + num of unival trees
pair<bool, int> unival(BinaryTreeNode<int> *root) {
	// empty tree check
    if (!root) return mp(true, 0);
    
    // leaf node
    if (!root->left and !root->right) return mp(true, 1);
    
    // different children values
    if ((root->left and root->left->data != root->data) or (root->right and root->right->data != root->data))
        return mp(false, 0);
    
    // left st
    auto left = unival(root->left);
    if (!left.first) return mp(false, 0);
    
    // right st
    auto right = unival(root->right);
    if (!right.first) return mp(false, 0);
    
    return mp(true, 1+left.second+right.second);
    
}

int ans;

void func(BinaryTreeNode<int>* root) {
    auto a = unival(root);
    if (a.first) {
        ans += a.second; return;
    }
    func(root->left);
    func(root->right);
}

int countUnivalTrees(BinaryTreeNode<int> *root)
{
    // Write your code here.
    ans = 0;
    func(root);
    return ans;
}
