// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
// right to left for the next level and alternate between).

/* For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  if (root == NULL) {
      return vector<vector<int> > ();
  }
  vector<vector<int> > result;

  queue<TreeNode*> nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while ( !nodesQueue.empty()) {
      int size = nodesQueue.size();
      vector<int> row(size);
      for (int i = 0; i < size; i++) {
          TreeNode* node = nodesQueue.front();
          nodesQueue.pop();

          // find position to fill node's value
          int index = (leftToRight) ? i : (size - 1 - i);

          row[index] = node->val;
          if (node->left) {
              nodesQueue.push(node->left);
          }
          if (node->right) {
              nodesQueue.push(node->right);
          }
      }
      // after this level
      leftToRight = !leftToRight;
      result.push_back(row);
  }
  return result;
}
