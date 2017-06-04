// Given an inorder traversal sequence and a preorder traversal sequence of a binary tree, write a program to reconstruct the tree. Assume
// each node has a unique key.

/* Solution:
A truly brute-force approach is to enumerate every binary tree on the inorder traversal sequence, and check if the preorder sequence from
that tree is the given one. The complexity is enormous.

Looking more carefully at the example, the preorder sequence gives us the key of the root node - it is the first node in the sequence. This
in turn allows us to split the inorder sequence into an inorder sequence for the left subtree, followed by the root, followed by the right
subtree.

The next insight is that we can use the left subtree inorder sequence to compute the preorder sequence for the left subtree from the preorder
sequence for the entire tree. A preorder traversal sequence consists of the root, followed by the preorder traversal sequence of the left
subtree. We know the number k of nodes in the left subtree from the location of the root in the inorder traversal sequence. Therefore, the
subsequence of k nodes after the root in the preorder traversal sequence is the preorder traversal sequence for the left subtree.

Implemented naively, the above algorithm has a time complexity of O(n^2). The worst-case corresponds to a skewed tree. Finding the root
within the inorder sequences takes time O(n). We can improve the time complexity by initially building a hash table from keys to their
positions in the inorder sequence. */

unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorder (const vector<int>& preorder, const vector<int>& inorder) {
  unordered_map<int, size_t> node_to_inorder_idx;
  for(size_t i = 0; i < inorder.size(); i++) {
    node_to_inorder_idx.emplace(inorder[i], i);
  }
  return BinaryTreeFromPreorderInorderHelper(preorder, 0, preorder.size(), 0, inorder.size(), node_to_inorder_idx);
}

// Builds the subtree with preorder[preorder_start : preorder_end - 1] and inorder[inorder_start : inorder_end - 1]
unique_ptr<BinaryTreeNode<int>> BinaryTreeFromPreorderInorderHelper(
  const vector<int>& preorder, size_t preorder_start, size_t preorder_end, size_t inorder_start, size_t inorder_end,
  const unordered_map<int, size_t>& node_to_inorder_idx) {
    if(preorder_end <= preorder_start || inorder_end <= inorder_start) {
      return nullptr;
    }
    size_t root_inorder_idx = node_to_inorder_idx.at(preorder[preorder_start]);
    size_t left_subtree_size = root_inorder_idx - inorder_start;

    return make_unique<BinaryTreeNode<int>>(BinaryTreeNode<int>{
      preorder[preorder_start],
      // Recursively builds the left subtree
      BinaryTreeFromPreorderInorderHelper(preorder, preorder_start + 1, preorder_start + 1 + left_subtree_size, inorder_start, root_inorder_idx, node_to_inorder_idx),
      // Recursively builds the right subtree
      BinaryTreeFromPreorderInorderHelper(preorder, preorder_start + 1 + left_subtree_size, preorder_end, root_inorder_idx + 1, inorder_end node_to_inorder_idx)
    });
  }

// The time complexity is O(n) - building the hash table takes O(n) time and the recursive reconstruction spends O(1) time per node. The space
// complexity is O(n + h) = O(n) - the size of the hash table plus the maximum depth of the function call stack.
