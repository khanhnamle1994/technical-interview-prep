// Write a nonrecursive program for computing the inorder traversal sequence for a binary tree. Assume nodes have parent fields.

/* Solution:
The standard idiom for an inorder traversal is traverse-left, visit-root, traverse-right. When we complete traversing a subtree, we need to
return to its parent. What we do after that depends on whether the subtree we returned from was the left subtree or right subtree of the
parent. In the former, we visit the parent, and then its right subtree; in the latter, we return from the parent itself.

One way to do this traversal without recursion is to record the parent node for each node we begin a traversal from. This can be done with a
hash table, and entails O(n) time and space complexity for the hash table, where n is the number of nodes, and h the height of the tree. The
space complexity can be reduced to O(h) by evicting a node from the hash table when we complete traversing the subtree rooted at it.

For this problem, since each node stores its parent, we do not need the hash table, which improves the space complexity to O(1).

To complete this algorithm, we need to know when we return to a parent if the just completed subtree was the parent's left child or a right
subtree. We achieve this by recording the subtree's root before we move to the parent. We can then compare the subtree's root with the parent's
left child. */

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree) {
  BinaryTreeNode<int> *prev = nullptr, *curr = tree.get();
  vector<int> result;

  while(curr != nullptr) {
    BinaryTreeNode<int> *next;
    if(curr->parent == prev) {
      // We came down to curr from prev
      if(curr->left != nullptr) {
        next = curr->left.get();
      } else {
        result.emplace_back(curr->data);
        // Done with left, so go right if right is not empty. Otherwise, go up.
        next = (curr->right != nullptr) ? curr->right.get() : curr->parent;
      }
    } else if(curr->left.get() == prev) {
      // We came up to curr from its left child
      result.emplace_back(curr->data);
      // Done with left, so go right if right is not empty. Otherwise, go up.
      next = (curr->right != nullptr) ? curr->right.get() : curr->parent;
    } else { // Done with both children, so move up
      next = curr->parent;
    }

    prev = curr;
    curr = next;
  }
  return result;
}

// The time complexity is O(n) and the additional space complexity is O(1)
