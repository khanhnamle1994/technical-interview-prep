// Given a binary tree, return the inorder traversal of its nodes' values.
/* For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> vector;
  stack<TreeNode *> stack;
  TreeNode *pCurrent = root;

  while(!stack.empty() || pCurrent)
  {
      if(pCurrent)
      {
          stack.push(pCurrent);
          pCurrent = pCurrent->left;
      }
      else
      {
          TreeNode *pNode = stack.top();
          vector.push_back(pNode->val);
          stack.pop();
          pCurrent = pNode->right;
      }
  }
  return vector;
}
