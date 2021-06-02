/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int sm = min(p->val,q->val), lg = max(p->val,q->val);
        if(root->val >= sm && root->val <= lg) return root;
        if(root->val > lg) return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};
