// Write a function to check that a binary tree is a valid binary search tree.
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

// Solution
// We do a depth-first walk through the tree, testing each node for validity as we go. A given node is valid if it's greater than all the ancestral nodes it's in the right sub-tree of and less than all the ancestral nodes it's in the left-subtree of. Instead of keeping track of each ancestor to check these inequalities, we just check the largest number it must be greater than (its lowerBound_) and the smallest number it must be less than (its upperBound_).

class NodeBounds
{
public:
    const BinaryTreeNode* node_;
    int lowerBound_;
    int upperBound_;

    NodeBounds(const BinaryTreeNode* node = nullptr,
            int lowerBound = numeric_limits<int>::min(),
            int upperBound = numeric_limits<int>::max()) :
        node_(node),
        lowerBound_(lowerBound),
        upperBound_(upperBound)
    {
    }
};

bool isBinarySearchTree(const BinaryTreeNode* root)
{
    // start at the root, with an arbitrarily low lower bound
    // and an arbitrarily high upper bound
    stack<NodeBounds> nodeAndBoundsStack;
    nodeAndBoundsStack.push(NodeBounds(root));

    // depth-first traversal
    while (!nodeAndBoundsStack.empty()) {
        const NodeBounds nodeBounds = nodeAndBoundsStack.top();
        nodeAndBoundsStack.pop();

        // if this node is invalid, we return false right away
        int nodeValue = nodeBounds.node_->value_;
        if (nodeValue <= nodeBounds.lowerBound_ || nodeValue >= nodeBounds.upperBound_) {
            return false;
        }

        if (nodeBounds.node_->left_ != nullptr) {
            // this node must be less than the current node
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->left_,
                nodeBounds.lowerBound_, nodeValue));
        }
        if (nodeBounds.node_->right_ != nullptr) {
            // this node must be greater than the current node
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->right_,
                nodeValue, nodeBounds.upperBound_));
        }
    }

    // if none of the nodes were invalid, return true
    // (at this point we have checked all nodes)
    return true;
}

// Instead of allocating a stack ourselves, we could write a recursive function that uses the call stack. This would work, but it would be vulnerable to stack overflow. However, the code does end up quite a bit cleaner:

bool isBinarySearchTree(const BinaryTreeNode* rootNode,
    const int lowerBound = numeric_limits<int>::min(),
    const int upperBound = numeric_limits<int>::max())
{
    if (rootNode == nullptr) {
        return true;
    }

    if (rootNode->value_ >= upperBound || rootNode->value_ <= lowerBound) {
        return false;
    }

    return isBinarySearchTree(rootNode->left_, lowerBound, rootNode->value_)
        && isBinarySearchTree(rootNode->right_, rootNode->value_, upperBound);
}

// Complexity
// O(n) time and O(n) space.

// The time cost is easy: for valid binary search trees, we’ll have to check all n nodes.

// Space is a little more complicated. Because we’re doing a depth first search, nodeAndBoundsStack will hold at most d nodes where d is the depth of the tree (the number of levels in the tree from the root node down to the lowest node). So we could say our space cost is O(d).

// But we can also relate d to n. In a balanced tree, d is \log_{2}{n}. And the more unbalanced the tree gets, the closer d gets to n.

// In the worst case, the tree is a straight line of right children from the root where every node in that line also has a left child. The traversal will walk down the line of right children, adding a new left child to the stack at each step. When the traversal hits the rightmost node, the stack will hold half of the nn total nodes in the tree. Half n is O(n), so our worst case space cost is O(n).
