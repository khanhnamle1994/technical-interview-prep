// Write a program that takes as input a BST and a value, and returns the first key that would appear in an inorder traversal which is
// greater than the input value.

/* Solution: We can find the desired node in O(n) time, where n is the number of nodes in the BST, by doing an inorder walk. This approach
does not use the BST property.

A better approach is to use the BST search idiom. We store the best candidate for the result and update that candidate as we iteratively
descend the tree, eliminating subtrees by comparing the keys stored at nodes with the input value. Specifically, if the current subtree's
root holds a value less than or equal to the input value, we search the right subtree. If the current subtree's root stires a key that is
greater than the input value, we search in the left subtree, updating the candidate to the current root. */

BSTNode<int>* FindFirstGreaterThanK(const unique_ptr<BSTNode<int>>& tree, int k) {
  BSTNode<int>* subtree = tree.get(), *first_so_far = nullptr;
  while(subtree) {
    if(subtree->data > k) {
      first_so_far = subtree;
      subtree = subtree->left.get();
    } else { // root and all keys in left subtree are <= k, so skip them
      subtree = subtree->right.get();
    }
  }
  return first_so_far;
}

// The time complexity is O(h) and space complexity is O(1)
