/* For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.

Example 1:
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
  if ((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
      return false;
  } else if (root1!= NULL) {
/*which means none of them is NULL, since with previous if condition we made sure both of them are NULL or none of them is NULL*/
      return ( (root1->val ==root2->val) && (
                   (flipEquiv (root1->right, root2->left) && flipEquiv (root1->left, root2->right) )  ||
                   (flipEquiv (root1->left, root2->left) && flipEquiv (root1->right, root2->right) )  )  );
  } else
      return true;
}
