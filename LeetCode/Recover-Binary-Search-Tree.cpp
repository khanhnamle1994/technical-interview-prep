// Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.

/* Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *root,vector<int> &v)
{
   if(root==NULL)
   {
       return;
   }
   inorder(root->left,v);
   v.push_back(root->val);
   inorder(root->right,v);
}

void convert(TreeNode *root,vector<int> &v)
{
   if(root==NULL)
   {
       return;

   }
   convert(root->left,v);
   root->val=v.front();
   v.erase(v.begin());
   convert(root->right,v);
}

void recoverTree(TreeNode* root) {
  vector<int> v;
  inorder(root,v);
  sort(v.begin(),v.end());
  convert(root,v);
}

// Basic solution to make a vector and find inorder traversal.
// Sort the vector.
// Then again do inorder traversal, replace the root element with first element of sorted vector and then delete the first element of sorted vector.

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

// Property of BST that it gives inorder traversal in ascending order.
