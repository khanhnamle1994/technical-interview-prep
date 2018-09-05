// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

/* Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True

Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* root, vector<int>& nums){
    if(root == NULL)return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    for(int i = 0, j = nums.size()-1; i<j;){
        if(nums[i] + nums[j] == k)return true;
        (nums[i] + nums[j] < k)? i++ : j--;
    }
    return false;
}

// The idea is to use a sorted array to save the values of the nodes in the BST by using an inorder traversal. Then, we use two pointers which begins from the start and end of the array to find if there is a sum k.

// Time Complexity: O(n), Space Complexity: O(n).
