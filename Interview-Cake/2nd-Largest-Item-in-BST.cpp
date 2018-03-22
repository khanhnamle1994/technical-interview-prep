// Write a function to find the 2nd largest element in a binary search tree.

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
// We start with a function for getting the largest value. The largest value is simply the "rightmost" one, so we can get it in one walk down the tree by traversing rightward until we don't have a right child anymore:

// note: this function assumes its input is non-null
int findLargest(const BinaryTreeNode* rootNode)
{
    const BinaryTreeNode* current = rootNode;
    const BinaryTreeNode* largest = nullptr;

    while (current) {
        if (!current->right_) {
            largest = current;
        }
        current = current->right_;
    }

    return largest->value_;
}

// With this in mind, we can also find the second largest in one walk down the tree. At each step, we have a few cases:
// 1. If we have a left subtree but not a right subtree, then the current node is the largest overall (the "rightmost") node. The second largest element must be the largest element in the left subtree. We use our findLargest() function above to find the largest in that left subtree!
// 2. If we have a right child, but that right child node doesn't have any children, then the right child must be the largest element and our current node must be the second largest element!
// 3. Else, we have a right subtree with more than one element, so the largest and second largest are somewhere in that subtree. So we step right.

int findLargest(const BinaryTreeNode* rootNode)
{
    const BinaryTreeNode* current = rootNode;
    while (current->right_) {
        current = current->right_;
    }
    return current->value_;
}

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

// Complexity
// We're doing one walk down our BST, which means O(h) time, where hh is the height of the tree (again, that's O(lgn) if the tree is balanced, O(n) otherwise). O(1) space.

// What We Learned
// Here we used a "simplify, solve, and adapt" strategy.

// The question asks for a function to find the second largest element in a BST, so we started off by simplifying the problem: we thought about how to find the first largest element.

// Once we had a strategy for that, we adapted that strategy to work for finding the second largest element.

// It may seem counter-intuitive to start off by solving the wrong question. But starting off with a simpler version of the problem is often much faster, because it's easier to wrap our heads around right away.

// One more note about this one:
// Breaking things down into cases is another strategy that really helped us here.

// Notice how simple finding the second largest node got when we divided it into two cases:

// 1. The largest node has a left subtree.
// 2. The largest node does not have a left subtree.
// Whenever a problem is starting to feel complicated, try breaking it down into cases.

// It can be really helpful to actually draw out sample inputs for those cases. This'll keep your thinking organized and also help get your interviewer on the same page.
