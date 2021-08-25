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

queue <BinaryTreeNode<int>*> q;
int ans = 0;
int burningTree(BinaryTreeNode<int> *root, int target) {
    if (!root) return 0;

    if (root->data == target) {
        // target burns first
//         cout << root->data << " ";

        // both of the following burn simultaneously
        // first we burn left child
        if (root->left) q.push(root->left);
        
        // then we burn right child
        if (root->right) q.push(root->right);

        // target found!
        return 1;
    }

    int left = burningTree(root->left, target);

    if (left) {
        int n = q.size();
        for (int i=0; i<n; ++i) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
//             cout << temp->data << ' ';
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        if (root->right) q.push(root->right);
//         cout << root->data << '\n';
        ans++;
        return 1;
    }

    int right = burningTree(root->right, target);

    if (right) {
        int n = q.size();
        for (int i=0; i<n; ++i) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
//             cout << temp->data << ' ';
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        if (root->left) q.push(root->left);
//         cout << root->data << '\n';
        ans++;
        return 1;
    }
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
  	queue<BinaryTreeNode<int>*> empty;
    swap(q, empty);
    ans = 0;
    int a = burningTree(root, start);
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; ++i) {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
//             cout << temp->data << ' ';
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
//         cout << '\n';
        ans++;
    }
    return ans;
}
