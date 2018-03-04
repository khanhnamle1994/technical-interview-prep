// Given a binary tree, find the leftmost value in the last row of the tree.
/* Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findBottomLeftValue(TreeNode* root, int& maxDepth, int& leftVal, int depth) {
  if (root == NULL) {
      return;
  }
  //Go to the left and right of each node
  findBottomLeftValue(root->left, maxDepth, leftVal, depth+1);
  findBottomLeftValue(root->right, maxDepth, leftVal, depth+1);

  //Update leftVal and maxDepth
  if (depth > maxDepth) {
      maxDepth = depth;
      leftVal = root->val;
  }
}

//Entry function
int findBottomLeftValue(TreeNode* root) {
  int maxDepth = 0;
  //Initialize leftVal with root's value to cover the edge case with single node
  int leftVal = root->val;
  findBottomLeftValue(root, maxDepth, leftVal, 0);
  return leftVal;
}
