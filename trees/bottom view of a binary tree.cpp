/*************************************************************
 
    Following is the Binary Tree node structure.

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
#define ff first
#define ss second

vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
    vector<int> left, right;
	// node, dist from root
    if (!root) return left;
    int mid_val = root->data;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    if (root->left) q.push(mp(root->left, -1));
    if (root->right) q.push(mp(root->right, 1));
    
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; ++i) {
            auto temp = q.front();
            q.pop();
            if (temp.ss < 0) {
                if (left.size() < (-1*temp.ss)) 
                    left.resize((-1*temp.ss), 0);
                left[(-1*temp.ss)-1] = temp.ff->data;
            } 
            else if (temp.ss == 0) mid_val = temp.ff->data;
            else {
                if (right.size() < temp.ss)
                    right.resize(temp.ss, 0);
                right[temp.ss-1] = temp.ff->data;
            }
            if (temp.ff->left) q.push(mp(temp.ff->left, temp.ss-1));
            if (temp.ff->right) q.push(mp(temp.ff->right, temp.ss+1));
        }
    }
    reverse(left.begin(), left.end());
    left.push_back(mid_val);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
