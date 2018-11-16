/* Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
  vector<TreeNode*> s;
  s.push_back(new TreeNode(pre[0]));
  for (int i = 1, j = 0; i < pre.size(); ++i) {
      TreeNode* node = new TreeNode(pre[i]);
      while (s.back()->val == post[j])
          s.pop_back(), j++;
      if (s.back()->left == NULL) s.back()->left = node;
      else s.back()->right = node;
      s.push_back(node);
  }
  return s[0];
}
