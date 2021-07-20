/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <queue>

void printLeftView(BinaryTreeNode<int> *root)
{
    //Write your code here
    if (!root) return;
    queue<BinaryTreeNode<int>*> pq, sq;
    pq.push(root);
    while (!pq.empty() or !sq.empty()) {
        BinaryTreeNode<int> *temp;
        if (!pq.empty())
        	cout << pq.front()->data << " ";
        while (!pq.empty()) {
        	temp = pq.front();
            if (temp->left) sq.push(temp->left);
            if (temp->right) sq.push(temp->right);
            pq.pop();
        }
        if (!sq.empty())
        	cout << sq.front()->data << " ";
        while (!sq.empty()) {
        	temp = sq.front();
            if (temp->left) pq.push(temp->left);
            if (temp->right) pq.push(temp->right);
            sq.pop();
        }
    }
}
