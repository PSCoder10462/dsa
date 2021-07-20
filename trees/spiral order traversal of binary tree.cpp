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
#include <stack>

void r(queue<BinaryTreeNode<int>*> &q) {
    stack<BinaryTreeNode<int>*> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
	// Write Your Code Here.
    vector<int> ans;
    if (!root) return ans;
    
    queue <BinaryTreeNode<int>*> p, s;
    
    p.push(root);
    
    BinaryTreeNode <int> *temp = nullptr;
    
    while (!p.empty() or !s.empty()) {
        while (!p.empty()) {
            temp = p.front();
            p.pop();
            ans.push_back(temp->data);
            if (temp->left)
                s.push(temp->left);
            if (temp->right)
                s.push(temp->right);
        }
        r(s);
        while (!s.empty()) {
            temp = s.front();
            s.pop();
            ans.push_back(temp->data);
            if (temp->right)
                p.push(temp->right);
            if (temp->left)
                p.push(temp->left);
        }
        r(p);
    }
    return ans;
}
