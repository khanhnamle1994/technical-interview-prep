// Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped
// while the others are not.

// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new
// value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

/* Using Recursion
We can traverse both the given trees in a preorder fashion. At every step, we check if the current node exists(isn't null) for both
the trees. If so, we add the values in the current nodes of both the trees and update the value in the current node of the first tree
to reflect this sum obtained. At every step, we also call the original function mergeTrees() with the left children and then with the
right children of the current nodes of the two trees. If at any step, one of these children happens to be null, we return the child of
the other tree(representing the corresponding child subtree) to be added as a child subtree to the calling parent node in the first
tree. At the end, the first tree will represent the required resultant merged binary tree.
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
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

/* Complexity Analysis
Time complexity : O(m)O(m).
A total of mm nodes need to be traversed. Here, mm represents the minimum number of nodes from the two given trees.

Space complexity : O(m)O(m).
The depth of the recursion tree can go upto mm in the case of a skewed tree. In average case, depth will be O(logm)O(logm). */
