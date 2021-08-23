/************************************************************

    Following is the Tree node structure:
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <queue>

int deepestLeavesSum(TreeNode<int>* root)
{
    // Write your code here.
	if (not root) return 0;
    int sum = 0;
    queue<TreeNode<int>*> p, q;
    p.push(root);
    
    while (!p.empty() or !q.empty()) {
        if (!p.empty()) sum = 0;
        while (!p.empty()) {
            TreeNode<int> *temp = p.front();
            p.pop();
            sum += temp->data;
        	if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        if (!q.empty()) sum = 0;
        while (!q.empty()) {
            TreeNode<int> *temp = q.front();
            q.pop();
            sum += temp->data;
            if (temp->left) p.push(temp->left);
            if (temp->right) p.push(temp->right);
        }
    }
    
    return sum;
    
}
