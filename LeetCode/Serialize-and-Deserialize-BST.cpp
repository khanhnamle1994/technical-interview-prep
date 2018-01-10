// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or
// memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization
// algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be
// deserialized to the original tree structure.

// The encoded string should be as compact as possible.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

inline void inorderDFS(TreeNode* root, string& order) {
   if (!root) return;
   char buf[4];
   memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
   for (int i=0; i<4; i++) order.push_back(buf[i]);
   inorderDFS(root->left, order);
   inorderDFS(root->right, order);
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  string order;
  inorderDFS(root, order);
  return order;
}

inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
  if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.

  int value;
  memcpy(&value, &buffer[pos], sizeof(int));
  if (value < minValue || value > maxValue) return NULL;
  
  TreeNode* node = new TreeNode(value);
  pos += sizeof(int);
  node->left = reconstruct(buffer, pos, minValue, value);
  node->right = reconstruct(buffer, pos, value, maxValue);
  return node;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  int pos = 0;
  return reconstruct(data, pos, INT_MIN, INT_MAX);
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
