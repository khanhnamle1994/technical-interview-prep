// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(root == NULL) return NULL;
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      if(left < right) {
        return right + 1;
      } else {
        return left + 1;
      }
    }
};
