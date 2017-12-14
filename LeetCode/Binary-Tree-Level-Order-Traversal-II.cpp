// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
// level by level from leaf to root).

/* For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > res;

void DFS(TreeNode* root, int level)
{
    if (root == NULL) return;
    if (level == res.size()) // The level does not exist in output
    {
        res.push_back(vector<int>()); // Create a new level
    }

    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level+1); // Go to the next level
    DFS(root->right,level+1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
  DFS(root, 0);
  return vector<vector<int> > (res.rbegin(), res.rend());
}

// In each function call, we pass in the current node and its level. If this level does not yet exist in the output
// container, then we should add a new empty level. Then, we add the current node to the end of the current level,
// and recursively call the function passing the two children of the current node at the next level. This algorithm
// is really a DFS, but it saves the level information for each node and produces the same result as BFS would.
