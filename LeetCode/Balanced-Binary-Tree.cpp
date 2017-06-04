// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node
// never differ by more than 1.

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
    int maxDepth(TreeNode * root){
        if (root==NULL){return 0;}
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }

    bool testNode(TreeNode * root){
        if (root==NULL) {return true;}
        if (abs(maxDepth(root->left) - maxDepth(root->right)) >1) {return false;}
        return (testNode(root->left) && testNode(root->right));
    }


    bool isBalanced(TreeNode *root) {
        return testNode(root);
    }
};
