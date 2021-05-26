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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        
        if ((p && !q) || (!p && q)) return false;
        
        if ((p->left && !q->left) || (!p->left && q->left)) return false;
        
        if ((p->right && !q->right) || (!p->right && q->right)) return false;
        
        if (p->val != q->val) return false;
        
        int pl, pr, ql, qr;
        pl = pr = ql = qr = 0;
        
        if (p->left) {
            pl = p->left->val;
            ql = q->left->val;
        }
        
        if (p->right) {
            pr = p->right->val;
            qr = q->right->val;
        }
        
        if (pl == ql && pr == qr)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        
        return false;
        
    }
};
