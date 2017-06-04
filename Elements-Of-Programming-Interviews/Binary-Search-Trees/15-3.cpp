// Write a program that takes as input a BST and an integer k, and returns the k largest elements in the BST in decreasing order.

/* Solution:
Begin with the desired nodes, and work backwards. We do this by recursing first on the right subtree and then on the left subtree. This
amounts to a reverse-inorder traversal. As soon as we visit k nodes, we can halt. As soon as the array has k elements, we return. We store
newer nodes at the end of the array, as per the problem specification. */

vector<int> FindKLargestInBST(const unique_ptr<BSTNode<int>>& tree, int k) {
  vector<int> k_largest_elements;
  FindKLargestInBSTHelper(tree, k, &k_largest_elements);
  return k_largest_elements;
}

void FindKLargestInBSTHelper(const unique_ptr<BSTNode<int>>& tree, int k, vector<int>* k_largest_elements) {
  // Performs reverse inorder traversal
  if(tree && k_largest_elements->size() < k) {
    FindKLargestInBSTHelper(tree->right, k, k_largest_elements);
    if(k_largest_elements->size() < k) {
      k_largest_elements->emplace_back(tree->data);
      FindKLargestInBSTHelper(tree->left, k, k_largest_elements);
    }
  }
}

// O(h + k) time complexity
