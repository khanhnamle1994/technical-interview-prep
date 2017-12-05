// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
/* For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// The basic idea is that we can construct the result of n node tree just from the result of n-1 node tree.
// Here's how we do it: only 2 conditions:
// 1) The nth node is the new root, so newroot->left = oldroot;
// 2) the nth node is not root, we traverse the old tree, every time the node in the old tree has a right child,
// we can perform: old node->right = nth node, nth node ->left = right child; and when we reach the end of the tree,
// don't forget we can also add the nth node here.

// One thing to notice is that every time we push a TreeNode in our result, I push the clone version of the root, and
// I recover what I do to the old node immediately. This is because you may use the old tree for several times.

TreeNode* clone(TreeNode* root){
    if(root == nullptr)
        return nullptr;
    TreeNode* newroot = new TreeNode(root->val);
    newroot->left = clone(root->left);
    newroot->right = clone(root->right);
    return newroot;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode *> res(1,nullptr);
    for(int i = 1; i <= n; i++) {
      vector<TreeNode *> tmp;
      for(int j = 0; j < res.size(); j++) {
        TreeNode* oldroot = res[j];
        TreeNode* root = new TreeNode(i);
        TreeNode* target = clone(oldroot);
        root->left = target;
        tmp.push_back(root);

        if(oldroot != nullptr) {
          TreeNode* tmpold = oldroot;
          while(tmpold->right != nullptr) {
            TreeNode* nonroot = new TreeNode(i);
            TreeNode *tright = tmpold->right;
            tmpold->right = nonroot;
            nonroot->left = tright;
            TreeNode *target = clone(oldroot);
            tmp.push_back(target);
            tmpold->right = tright;
            tmpold = tmpold->right;
          }
          tmpold->right = new TreeNode(i);
          TreeNode *target = clone(oldroot);
          tmp.push_back(target);
          tmpold->right = nullptr;
        }
      }
      res = tmp;
    }
    return res;
}
