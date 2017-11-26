// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in
// this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on
// the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

/* Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int rob(TreeNode* root) {
    int l, r;
    return tryRob(root, l, r);
}

int tryRob(TreeNode* root, int& l, int& r) {
    if (!root)
        return 0;

    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = tryRob(root->left, ll, lr);
    r = tryRob(root->right, rl, rr);

    return max(root->val + ll + lr + rl + rr, l + r);
}
