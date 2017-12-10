// Given a binary tree, determine if it is a valid binary search tree (BST).

/* Assume a BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isValidBST(TreeNode* root) {
  TreeNode* prev = NULL;
  return validate(root, prev);
}

bool validate(TreeNode* node, TreeNode* &prev) {
  if (node == NULL) return true;
  if (!validate(node->left, prev)) return false;
  if (prev != NULL && prev->val >= node->val) return false;
  prev = node;
  return validate(node->right, prev);
}
