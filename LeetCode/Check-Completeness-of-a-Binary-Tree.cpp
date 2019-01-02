/* Given a binary tree, determine if it is a complete binary tree.

Example 1:
Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isCompleteTree(TreeNode* root) {
  vector<TreeNode*> bfs;
  bfs.push_back(root);
  int i = 0;
  while (i < bfs.size() && bfs[i]) {
      bfs.push_back(bfs[i]->left);
      bfs.push_back(bfs[i]->right);
      i++;
  }
  while (i < bfs.size() && !bfs[i])
      i++;
  return i == bfs.size();
}
