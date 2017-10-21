// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

/* For example:
Given binary tree [3,9,20,null,null,15,7],
    3
  / \
 9  20
   /  \
  15   7
return its level order traversal as:
[
  [3],
  [9,20],
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

vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth) {
  if(root == NULL) return;
  if(ret.size() == depth) {
    ret.push_back(vector<int>());
  }

  ret[depth].push_back(root->val);
  buildVector(root->left, depth + 1);
  buildVector(root->right, depth + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
  buildVector(root, 0);
  return ret;
}
