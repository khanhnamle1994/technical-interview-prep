// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
// ordered from top to bottom.

/* For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void recursion(TreeNode *root, int level, vector<int> &res)
{
    if(root == NULL) return;
    if(res.size() < level) res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    recursion(root, 1, res);
    return res;
}
