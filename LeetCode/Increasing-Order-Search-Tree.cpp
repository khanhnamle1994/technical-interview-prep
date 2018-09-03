// Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

/* Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

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
           6
            \
             7
              \
               8
                \
                 9  */

                 /**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

TreeNode* increasingBST(TreeNode* root) {
  if(!root)
      return root;
  TreeNode* newroot = NULL, *temp;
  list<TreeNode*> st;
  while(!st.empty() || root)
  {
      while(root)
      {
          st.push_front(root);
          root = root->left;
      }
      root = st.front();
      st.pop_front();
      root->left = NULL;
      if(!newroot)
      {
          newroot = root;
          temp = root;
      }
      else
      {
          temp->right = root;
          temp->left = NULL;
          temp=temp->right;
      }
      root = root->right;
  }
  return newroot;
}
