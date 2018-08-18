// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
/* Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11]. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<double> averageOfLevels(TreeNode* root) {
  vector<double> res;
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()) {
      long temp = 0;
      int s = q.size();
      for(int i = 0; i < s; i++) {
          TreeNode* t = q.front();
          q.pop();
          if(t->left) q.push(t->left);
          if(t->right) q.push(t->right);
          temp += t->val;
      }
      res.push_back((double)temp / s);
  }
  return res;
}
