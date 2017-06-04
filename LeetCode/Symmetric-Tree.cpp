// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

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
    bool isSymmetric(TreeNode* root) {
        return isSym(root, root);
    }

    bool isSym(TreeNode* lr, TreeNode* rr) {
        if(!lr && !rr)
            return true;
        if((!lr && rr) || (lr && !rr))
            return false;
        if(lr == rr)
            return isSym(lr->left, lr->right); // lr and rr both point to root
        if(lr->val != rr->val)
            return false;
        return isSym(lr->left, rr->right) && isSym(lr->right, rr->left);
    }
};
