// Design efficient functions for removing keys in a BST. Assume that all elements in the BST are unique.

/* Solution:
Deletion begins with first identifying the node containing the key to be deleted. Suppose the node to be deleted has no children. Then
we remove the corresponding child field in the parent of the node to be deleted. If the node to be deleted has a single child, we update
the parent of the node to be deleted to have that child in place of the node to be deleted.

Now we consider the case where the node to be deleted has 2 children. We can effectively delete the node by replacing its contents with
the contents of its successor (which must appear in the right subchild), and then deleting the successor (which is relatively straightforward
since it cannot have a left child) */

class BinarySearchTree {
public:
  bool Delete(int key) {
    // Find the node with key
    TreeNode *curr = root_.get(), *parent = nullptr;
    while (curr && curr->data != key) {
      parent = curr;
      curr = key < curr->data ? curr->left.get() : curr->right.get();
    }

    if(!curr) {
      // There's no node with key in this tree
      return false;
    }

    TreeNode *key_node = curr;
    if(key_node->right) {
      // Finds the minimum of the right subtree
      TreeNode *r_key_node = key_node->right.get(), *r_parent = key_node;
      while(r_key_node->left) {
        r_parent = r_key_node;
        r_key_node = r_key_node->left.get();
      }
      key_node->data = r_key_node->data;
      // Moves links to erase the node
      if(r_parent->left.get() == r_key_node) {
        r_parent->left.reset(r_key_node->right.release());
      } else {
        r_parent->right.reset(r_key_node->right.release());
      }
    } else {
      // Updates root_ link if needed
      if(root_.get() == key_node) {
        root_.reset(key_node->left.release());
      } else {
        if(parent->left.get() == key_node) {
          parent->left.reset(key_node->left.release());
        } else { // parent->right.get() == key_node
          parent->right.reset(key_node->left.release());
        }
      }
    }
    return true;
  }

private:
  struct TreeNode {
    int data;
    unique_ptr<TreeNode> left, right;
  };

  unique_ptr<TreeNode> root_ = nullptr;
};
