// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

/* Assume a BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than or equal to the node's key.
* The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
* Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> findMode(TreeNode* root) {
  unordered_map<int, int> map;
  vector<int> result;
  int modeCount = getModeCount(root, map);

  for(pair<int,int> p : map) {
      if(p.second == modeCount) {
          result.push_back(p.first);
      }
  }

  return result;
}

/**
 * Traverse the tree using depth first search.
 * Return the mode count (i.e. The count of a repeated number that occurs the most.) of the tree.
 */

int getModeCount(TreeNode* root, unordered_map<int, int> &map) {
  if(root == NULL)
      return 0;
  map[root->val]++;

  return max(map[root->val],max(getModeCount(root->left, map),getModeCount(root->right, map)));
}
