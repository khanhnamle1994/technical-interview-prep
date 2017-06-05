// Design an algorithm that takes as input a BST and 2 nodes, and returns the LCA of the 2 nodes. Assume all keys are distinct.

/* Solution:
Let s and b be the 2 nodes whose LCA we are to compute, and without loss of generality assume the key at s is smaller. Consider the keys
stored at the root of the BST. There are 4 possibilities:
1 - If the root's key is the same as that stored at s or at b, we are done - the root is the LCA
2 - If the key at s is smaller than the key at the root, and the key at b is greater than the key at the root, the root is the LCA
3 - If the keys at s and b are both smaller than the key at the root, the LCA must lie in the left subtree of the root
4 - If the keys at s and b are both larger than the key at the root, the LCA must lie in the right subtree of the root */

BSTNode<int>* FindLCA(const unique_ptr<BSTNode<int>>& tree, const unique_ptr<BSTNode<int>>& s, const unique_ptr<BSTNode<int>>& b) {
  auto* p = tree.get();
  while(p->data < s->data || p->data > b->data) {
    // Keep searching since p is outside of [s, b]
    while(p->data < s->data) {
      p = p->right.get(); // LCA must be in p's right child
    }
    while(p->data > b->data) {
      p = p->left.get(); // LCA must be in p's left child
    }
  }
  // Now, s->data <= p->data && p->data <= b->data
  return p;
}

// Since we descend one level with each iteration, the time complexity is O(h), where h is the height of the tree
