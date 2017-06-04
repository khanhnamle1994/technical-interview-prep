// Write a program that takes as input a binary tree and checks if the tree satisfies the BST property.

/* Solution:
Check the constraints on the values for each subtree. The initial constraint comes from the root. Every node in its left (right) subtree
must have a key less than or equal (greater than or equal) to the key at the root. This idea generalizes: if all nodes in a tree must have
keys in the range [l, u] and the key at the root is w, then all keys in the left subtree must be in the range [l, w], and all keys stored
in the right subtree must be in the range [w, u]. */

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return AreKeysInRange(tree, numeric_limits<int>::min(), numeric_limits<int>::max());
}

bool AreKeysInRange(const unique_ptr<BinaryTreeNode<int>>& tree, int low_range, int high_range) {
  if(tree == nullptr) {
    return true;
  } else if(tree->data < low_range || tree->data > high_range) {
    return false;
  }

  return AreKeysInRange(tree->left, low_range, tree->data) && AreKeysInRange(tree->right, tree->data, high_range);
}

// O(n) time complexity and O(h) additional space complexity
