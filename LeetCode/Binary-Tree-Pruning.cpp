// We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
// Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
// (Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

/* Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]

Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* pruneTree(TreeNode* root) {
  if (!root) return NULL;
  root->left = pruneTree(root->left);
  root->right = pruneTree(root->right);
  if (!root->left && !root->right && root->val == 0) return NULL;
  return root;
}
