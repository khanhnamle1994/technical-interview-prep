// Write a program that checks whether a binary tree is symmetric.

/* Solution:
We can test if a tree is symmetric by computing its mirror image and seeing if the mirror image is equal to the original tree. Computing the
mirror image of a tree is as simple as swapping the left and right subtrees, and recursively continuing. The time and space complexity are
both O(n), where n is the number of nodes in the tree.

The insight to a better algorithm is that we do not need to construct the mirrored subtrees. All that is important is whether a pair of subtrees
are mirror images. As soon as a pair fails the test, we can short circuit the check to false. */

bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& subtree_0, nique_ptr<BinaryTreeNode<int>>& subtree_1) {
  if(subtree_0 == nullptr && subtree_1 == nullptr) {
    return true;
  } else if(subtree_0 != nullptr && subtree_1 != nullptr) {
    return subtree_0->data == subtree_1->data && CheckSymmetric(subtree_0->left, subtree_1->right) && CheckSymmetric(subtree_0->right, subtree_1->left);
  }

  // One subtree is empty, and the other is not
  return false;
}

// The time complexity and space complexity are O(n) and O(h), respectively, where n is the number of nodes in the tree and h is the height of the tree
