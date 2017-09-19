// Write a function to see if a binary tree is "superbalanced" (a new tree property we just made up).
// A tree is "superbalanced" if the difference between the depths of any two leaf nodes ↴ is no greater than one.

// Here's a sample binary tree node class:
class BinaryTreeNode
{
public:
  int value_;
  BinaryTreeNode* left_;
  BinaryTreeNode* right_;

  BinaryTreeNode(int value) :
      value_(value),
      left_(nullptr),
      right_(nullptr)
  {
  }

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

/* Solution:
We do a depth-first walk through our tree, keeping track of the depth as we go. When we find a leaf, we throw its depth into an array
of depths if we haven't seen that depth already.

Each time we hit a leaf with a new depth, there are two ways that our tree might now be unbalanced:
1> There are more than 2 different leaf depths
2> There are exactly 2 leaf depths and they are more than 1 apart. */

bool isBalanced(const BinaryTreeNode* treeRoot)
{

  // a tree with no nodes is superbalanced, since there are no leaves!
  if (treeRoot == nullptr) {
      return true;
  }

  // will have up to 3 elements
  size_t depths[3];
  size_t depthCount = 0;

  // nodes will store pairs of a node and the node's depth
  stack<pair<const BinaryTreeNode*, size_t>> nodes;
  nodes.push(make_pair(treeRoot, 0));

  while (!nodes.empty()) {

      // get a node and its depth from the top of stack and pop it
      const BinaryTreeNode* node = nodes.top().first;
      size_t depth = nodes.top().second;
      nodes.pop();

      // case: we found a leaf
      if (!node->left_ && !node->right_) {

          // we only care if it's a new depth
          if (depthCount == 0 ||
              find(depths, depths + depthCount, depth) == depths + depthCount) {
              depths[depthCount] = depth;
              ++depthCount;

              // two ways we might now have an unbalanced tree:
              //   1) more than 2 different leaf depths
              //   2) 2 leaf depths that are more than 1 apart
              if (depthCount > 2 ||
                      (depthCount == 2 &&
                      max(depths[0], depths[1]) - min(depths[0], depths[1]) > 1)) {
                  return false;
              }
          }
      }

      // case: this isn't a leaf - keep stepping down
      else {
          if (node->left_) {
              nodes.push(make_pair(node->left_, depth + 1));
          }
          if (node->right_) {
              nodes.push(make_pair(node->right_, depth + 1));
          }
      }
  }

  return true;
}

/* Complexity:
O(n) time and O(n) space.

For time, the worst case is the tree is balanced and we have to iterate over all nn nodes to make sure.

For the space cost, we have two data structures to watch: depths and nodes.

depths will never hold more than three elements, so we can write that off as O(1).

Because we’re doing a depth first search, nodes will hold at most d nodes where d is the depth of the tree (the number of levels in the
tree from the root node down to the lowest node). So we could say our space cost is O(d).

But we can also relate d to n. In a balanced tree, d is O(\log_{2}(n)). And the more unbalanced the tree gets, the closer d gets to n.

In the worst case, the tree is a straight line of right children from the root where every node in that line also has a left child.
The traversal will walk down the line of right children, adding a new left child to nodes at each step. When the traversal hits the
rightmost node, nodes will hold half of the n total nodes in the tree. Half n is O(n), so our worst case space cost is O(n). */
