// a better(faster) solution exists!

/************************************************************

    Following is the Binary Tree node class
    
    template <typename T = int>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };

************************************************************/

#include <stack>

TreeNode<int> *constructSBT(vector<int> &pre, vector<char> &typeNL)
{
    // Write your code here.
    stack <TreeNode<int>*> s;
    TreeNode<int> *root = new TreeNode<int> (pre[0]), *temp;
    temp = root;
    s.push(root);
    for (int i=1; i<pre.size(); ++i) {
        if (!temp->left) {
        	temp->left = new TreeNode<int>(pre[i]);
        	if (typeNL[i] == 'N') {
                temp = temp->left;
                s.push(temp);
            }
        }
        else if (!temp->right) {
            temp->right = new TreeNode<int>(pre[i]);
			s.pop();
            if (typeNL[i] == 'N') {
                temp = temp->right;
            	s.push(temp);
            }
            else 
                if (!s.empty())
                	temp = s.top();
        }
    }
    return root;
}
