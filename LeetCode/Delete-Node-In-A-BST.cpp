// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference of the BST
// The deletion can be divided into 2 stages:
// 1 - Search for the node to be removed
// 2 - If the node is found, delete the node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 clas Solution {
 public:
   TreeNode* deleteNode(TreeNode* root, int key) {
     if(!root) {
       return nullptr;
     }
     if(root->val > key) {
       root->left = deleteNode(root->left, key);
     } else if(root->val < key) {
       root->right = deleteNode(root->right, key);
     } else {
       if(!root->left) {
         auto right = root->right;
         delete root;
         return right;
       } else if (!root->right) {
         auto left = root->left;
         delete root;
         return left;
       } else {
         auto successor = root->right;
         while(successor->left) {
           successor = successor->left;
         }
         root->val = successor->val;
         root->right = deleteNode(root->right, successor->val);
       }
     }
     return root;
   }
 };
