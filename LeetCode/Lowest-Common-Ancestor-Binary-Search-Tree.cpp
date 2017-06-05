// Given a BST, find the LCA of 2 given nodes in the BST

/* Analysis: Remember to take advantage of the property of BST, which is, node->left->val < node->val < node->right->val. Moreover, both
p and q will be the descendants of the root of the subtree that contains both of them. And the root with the largest depth is just the
lowest common ancestor. */

// Recursive Solution
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    if(p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return root;
  }
};

// Iterative Solution
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;
    while(true) {
      if(p->val < cur->val && q->val < cur->val) {
        cur = cur->left;
      } else if(p->val > cur->val && q->val > cur->val) {
        cur = cur->right;
      } else {
        return cur;
      }
    }
  }
};
