// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

/* Analysis:
The idea is to keep an array of length K, to hold the k smallest nodes. Each time when visiting a node, save it to the array if the array
is not full. The end (or front depending on your save order) element is the Kth smallest node.

If insert and delete operations often happen, we can only check this array of length K, if any node in this array is deleted, search and
insert the next element from the array's last node. If new node is inserted as the child of one node in the array, insert this node to
its proper position of array, and move every other accordingly. */

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
    void search(TreeNode* root, int &k, vector<TreeNode*> &list_k) {
      if(root->left) {
        search(root->left, k, list_k);
      }

      k = k - 1;
      if(k >= 0) {
        list_k[k] = root;
      } else {
        return;
      }

      if(root->right) {
        search(root->right, k, list_k);
      }
    }

    int kthSmallest(TreeNode* root, int k) {
      vector<TreeNode*> list_k(k, NULL);
      search(root, k, list_k);
      return list_k[0]->val;
    }
};
