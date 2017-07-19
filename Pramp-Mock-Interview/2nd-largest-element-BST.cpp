// Write a function to find the 2nd largest element in a binary search tree

#include <iostream>
using namespace std;

// Binary Tree Node class
class BinaryTreeNode {
public:
  int value_;
  BinaryTreeNode* left_;
  BinaryTreeNode* right_;

  BinaryTreeNode(int value) : value_(value), left_(nullptr), right_(nullptr) { }

  ~BinaryTreeNode()
  {
      delete left_;
      delete right_;
  }

  BinaryTreeNode * insertLeft(int value)
  {
      this->left_ = new BinaryTreeNode(value);
      return this->left_;
  }

  BinaryTreeNode * insertRight(int value)
  {
      this->right_ = new BinaryTreeNode(value);
      return this->right_;
  }
};

// Implementation

// Function for getting the largest value - rightmost one
int findLargest(const BinaryTreeNode* rootNode)
{
  const BinaryTreeNode* current = rootNode;
  while (current->right_) {
      current = current->right_;
  }
  return current->value_;
}

// Function for getting the second largest value
int findSecondLargest(const BinaryTreeNode* rootNode)
{
  if (!rootNode->left_ && !rootNode->right_) {
      throw invalid_argument("Tree must have at least 2 nodes");
  }

  const BinaryTreeNode* current = rootNode;

  while (true) {

      // case: current is largest and has a left subtree
      // 2nd largest is the largest in that subtree
      if (current->left_ && !current->right_) {
          return findLargest(current->left_);
      }

      // case: current is parent of largest, and largest has no children,
      // so current is 2nd largest
      if (current->right_ &&
              !current->right_->left_ &&
              !current->right_->right_) {
          break;
      }

      // step to the right
      current = current->right_;
  }

  return current->value_;
}

// Complexity:
// We're doing one walk down our BST, which means O(h) time, where h is the height of the tree
// (again, that's O(lgn) if the tree is balanced, O(n) otherwise). O(1) space.
