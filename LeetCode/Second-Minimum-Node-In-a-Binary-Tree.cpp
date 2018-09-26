// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

// If no such second minimum value exists, output -1 instead.

/* Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findSecondMinimumValue(TreeNode* root) {
  if (!root) return -1;
  int ans = minval(root, root->val);
  return ans;
}

int minval(TreeNode* p, int first) {
  if (p == nullptr) return -1;
  if (p->val != first) return p->val;
  int left = minval(p->left, first), right = minval(p->right, first);
  // if all nodes of a subtree = root->val,
  // there is no second minimum value, return -1
  if (left == -1) return right;
  if (right == -1) return left;
  return min(left, right);
}
