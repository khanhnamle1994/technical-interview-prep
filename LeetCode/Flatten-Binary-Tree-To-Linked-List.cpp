// Given a binary tree, flatten it to a linked list in-place.

/* For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6 */

void flatten(TreeNode* root) {
    TreeNode* now = root;
    while (now) {
      if (now->left) {
        // Find the current node's prenode that links to current node's right subtree
        TreeNode* pre = now->left;
        while (pre->right) {
          pre = pre->right;
        }
        pre->right = now->right;
        // Use current node's left subtree to replace its right subtree
        // Original right subtree is already linked by current node's prenode
        now->right = now->left;
        now->left = NULL;
      }
      now = now->right;
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
