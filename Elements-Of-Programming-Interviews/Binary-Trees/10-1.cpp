// Write a program that takes as input the root of a binary tree and checks whether the tree is height-balanced.

/* Solution:
Here is a brute-force algorithm. Compute the height for the tree rooted at each node x recursively. The basic computation is to compute the
height for each node starting from the leaves, and proceeding upwards. For each node, we check if the difference in heights of the left and
right children is greater than one. We can store the heights in a hash table, or in a new field in the nodes. This entails O(n) storage and
O(n) time, where n is the number of nodes of the tree.

We can solve this problem using less storage by observing that we do not need to store the heights of all nodes at the same time. Once we
are done with a subtree, all we need is whether it is height-balanced, and if so, what its height is - we do not need any information about
descendants of the subtree's root. */

struct BalancedStatusWithHeight {
  bool balanced;
  int height;
};

bool isBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return CheckBalanced(tree).balanced;
}

// First value of the return value indicates if tree is balanced, and if balanced the second value of the return value is the height of tree
BalancedStatusWithHeight CheckBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  if(tree == nullptr) {
    return {true, -1}; // Base case
  }

  auto left_result = CheckBalanced(tree->left);
  if(!left_result.balanced) {
    return {false, 0}; // Left subtree is not balanced
  }

  auto right_result = CheckBalanced(tree->right);
  if(!right_result.balanced) {
    return {false, 0}; // Right subtree is not balanced
  }

  bool is_balanced = abs(left_result.height - right_result.height) <= 1;
  int height = max(left_result.height, right_result.height) + 1;
  return {is_balanced.height};
}

// The program implements a postorder traversal with some calls possibly being eliminated because of early termination. Specifically, if any
// left subtree is not height-balanced, we do not need to visit the corresponding right subtree. The function call stack corresponds to a
// sequence of calls from the root through the unique path to the current node, and the stack height is therefore bounded by the height of
// the tree, leading to an O(h) space bound. The time complexity is the same as that for a postorder traversal, namely O(n).
