/* Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

Example 1:
Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int depth(TreeNode *root) {
  return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
  int d = depth(root->left) - depth(root->right);
  return !d ? root : subtreeWithAllDeepest(d > 0 ? root->left : root->right);
}
