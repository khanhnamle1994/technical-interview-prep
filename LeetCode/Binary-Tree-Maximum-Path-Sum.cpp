// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

/* Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxPathSumHelper(TreeNode *root, int &res) {
   if (!root) {
       return 0;
   }

   int lsum = maxPathSumHelper(root->left, res);
   int rsum = maxPathSumHelper(root->right, res);

   int r = root->val;      // root->val;
   r = max(r, r + lsum);   // max (rootv, rootv + lsum)
   r = max(r, r + rsum);   // max (rootv, rootv + lsum, rootv + rsum, rootv + lsum + rsum)
   res = max(r, res);      // max of prior computed result or new one.

   return max(root->val, root->val + max(lsum, rsum)); // current max.
}

int maxPathSum(TreeNode* root) {
  if (!root)
      return 0;

  int res = root->val;

  maxPathSumHelper(root, res);

  return res;
}
