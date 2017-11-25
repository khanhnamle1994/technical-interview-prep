// Given a binary tree, return the preorder traversal of its nodes' values.

/* For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> preorderTraversal(TreeNode* root) {
  stack<TreeNode*> nodeStack; // create an empty stack
  vector<int> result;

  // base case
  if (root == NULL) return result;
  nodeStack.push(root); // push root node into the stack

  while (!nodeStack.empty()) {
    TreeNode* node = nodeStack.top();
    result.push_back(node->val);
    nodeStack.pop(); // pop an item from the stack and print it
    if (node->right) {
      nodeStack.push(node->right); // push the right child of popped item to stack
    }
    if (node->left) {
      nodeStack.push(node->left); // push the left child of popped item to stack
    }
  }

  return result;
}
