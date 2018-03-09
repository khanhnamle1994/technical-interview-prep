// You need to find the largest value in each row of a binary tree.
/* Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> solution;

void helper(TreeNode* node, int cl) {
  if (node == NULL) {
      return;
  }
  if (solution.size() < cl + 1) {
      solution.push_back(node->val);
  } else {
      if (solution[cl] < node->val) {
          solution[cl] = node->val;
      }
  }
  helper(node->left, cl + 1);
  helper(node->right, cl + 1);
}

vector<int> largestValues(TreeNode* root) {
  if(root == NULL) {
    return solution;
  }

  helper(root, 0);
  return solution;
}
