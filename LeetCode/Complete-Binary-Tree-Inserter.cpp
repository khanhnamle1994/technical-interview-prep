/* A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:
>> CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
>> CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
>> CBTInserter.get_root() will return the head node of the tree.

Example 1:
Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]

Example 2:
Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> tree;

CBTInserter(TreeNode* root) {
  tree.push_back(root);
  for(int i = 0; i < tree.size();++i) {
      if (tree[i]->left) tree.push_back(tree[i]->left);
      if (tree[i]->right) tree.push_back(tree[i]->right);
  }
}

int insert(int v) {
  int N = tree.size();
  TreeNode* node = new TreeNode(v);
  tree.push_back(node);
  if (N % 2)
      tree[(N - 1) / 2]->left = node;
  else
      tree[(N - 1) / 2]->right = node;
  return tree[(N - 1) / 2]->val;
}

TreeNode* get_root() {
  return tree[0];
}
