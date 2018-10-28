/* Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  vector<TreeNode*> stk;
  for (int i = 0; i < nums.size(); ++i)
  {
      TreeNode* cur = new TreeNode(nums[i]);
      while (!stk.empty() && stk.back()->val < nums[i])
      {
          cur->left = stk.back();
          stk.pop_back();
      }
      if (!stk.empty())
          stk.back()->right = cur;
      stk.push_back(cur);
  }
  return stk.front();
}

/* The key idea is:
1 - We scan numbers from left to right, build the tree one node by one step;
2 - We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
3 - For each number, we keep pop the stack until empty or a bigger number; The bigger number (if exist, it will be still in stack) is current number's root, and the last popped number (if exist) is current number's left child (temporarily, this relationship may change in the future); Then we push current number into the stack. */
