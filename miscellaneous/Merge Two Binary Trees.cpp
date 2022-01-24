/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root1, TreeNode* root2, TreeNode* &root) {
        if (!root1 and !root2) return;
        if (root1 and root2) {
            root = new TreeNode (root1->val + root2->val);
            func(root1->left, root2->left, root->left);
            func(root1->right, root2->right, root->right);
        } else if (root1) {
            root = new TreeNode (root1->val);
            func(root1->left, nullptr, root->left);
            func(root1->right, nullptr, root->right);
        } else {
            root = new TreeNode (root2->val);
            func(nullptr, root2->left, root->left);
            func(nullptr, root2->right, root->right);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root = nullptr;
        func(root1, root2, root);
        return root;
    }
};
