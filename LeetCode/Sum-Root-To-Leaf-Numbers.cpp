// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers.

/* For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. *.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int sum;

void DFS(TreeNode *&node, int currentSum) {
  currentSum = currentSum * 10 + node->val;
  if(!node->left && !node->right)
      sum += currentSum;
  if(node->left)
      DFS(node->left, currentSum);
  if(node->right)
      DFS(node->right, currentSum);
}

int sumNumbers(TreeNode* root) {
  if(!root) return 0;
  sum = 0;
  DFS(root, 0);
  return sum;
}
