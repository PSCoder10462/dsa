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
    
    std::vector <int> ans;
    
    void func(TreeNode* root) {
        if (root == NULL) return;
        
        func(root->left);
        
        ans.push_back(root->val);
        
        func(root->right);
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        func(root);
        return ans;
    }
};
