/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
#include <vector>

vector<int> v;
int itr;

void initVec(BinaryTreeNode *root) {
    if (!root) return ;
    initVec(root->left);
    v.push_back(root->data);
    initVec(root->right);
}

BinaryTreeNode *minHeap(BinaryTreeNode*root) {
    if (!root) return nullptr;
    root->data = v[itr++];
    root->left = minHeap(root->left);
    root->right = minHeap(root->right);
    return root;
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    v.clear();
    itr = 0;
    
    initVec(root);
	return minHeap(root);
}
