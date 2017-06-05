// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path
// equals the given sum.

/* Analysis:
This is a basic practice for depth first search algorithm.
The way of thinking this problem:
+ This question requires only true/false return, so the final result is the "or" operation of all the possible root-to-leaf path.
+ Parameters used in recursion should only be the sum value and the current node.
+ Condition:  if the sum == 0 and the node is leaf node return true,
                        if the sum != 0 and the node is NULL, return false
                        else return go root.left, sum-val || go root.right, sum-val
+ How to check if the current node is a leaf node?  Both its left and right children all empty. */

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) { return false; }
        if((root->left == NULL) && (root->right == NULL) && (sum-root->val == 0)) { return true; }
        return ((hasPathSum(root->left, sum-root->val)) || hasPathSum(root->right, sum-root->val));
    }
};
