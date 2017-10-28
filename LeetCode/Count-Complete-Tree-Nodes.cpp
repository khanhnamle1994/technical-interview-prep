// Given a complete binary tree, count the number of nodes.

// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are
// as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int countNodes(TreeNode* root) {
    if(!root)
      return 0;

    int hl=0, hr=0;
    TreeNode *l=root, *r=root;

    while(l) {
      hl++;l=l->left;
    }
    while(r) {
      hr++;r=r->right;
    }

    if(hl==hr)
      return pow(2,hl) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
