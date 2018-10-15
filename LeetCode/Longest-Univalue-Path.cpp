// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

/* Example 1:
Input:
              5
             / \
            4   5
           / \   \
          1   1   5
Output:
2

Example 2:
Input:
              1
             / \
            4   5
           / \   \
          4   4   5
Output:
2 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode* node, int& lup) {
 int l = node->left ? dfs(node->left, lup) : 0;
 int r = node->right ? dfs(node->right, lup) : 0;
 int resl = node->left && node->left->val == node->val ? l + 1 : 0;
 int resr = node->right && node->right->val == node->val ? r + 1 : 0;
 lup = max(lup, resl + resr);
 return max(resl, resr);
}

int longestUnivaluePath(TreeNode* root) {
  int lup = 0;
  if (root) dfs(root, lup);
  return lup;
}
