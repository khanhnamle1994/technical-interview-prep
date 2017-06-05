// Given an array where elements are sorted in ascending order, convert it to a height-balanced BST

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
   TreeNode* sortedArrayToBST(vector<int>& nums) {
     return arrayToBST(nums, 0, nums.size() - 1);
   }

   TreeNode* arrayToBST(vector<int>& num, int start, int end) {
     if(start >= end) return NULL;
     int mid = start + (end - start) / 2;
     TreeNode* root = new TreeNode(num[mid]);
     root->left = arrayToBST(num, start, mid - 1);
     root->right = arrayToBST(num, mid + 1, end);
     return root;
   }
 }
