// You have a linked list ↴ and want to find the kkth to last node.

// Write a function kthToLastNode() that takes an integer kk and the headNode of a singly-linked list, and returns the kkth to last node in the list.

// For example:
class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode* next_;

    LinkedListNode(int intValue) :
        intValue_(intValue),
        next_(nullptr)
    {
    }
};

LinkedListNode* a = new LinkedListNode(1);
LinkedListNode* b = new LinkedListNode(2);
LinkedListNode* c = new LinkedListNode(3);
LinkedListNode* d = new LinkedListNode(4);
LinkedListNode* e = new LinkedListNode(5);

a->next_ = b;
b->next_ = c;
c->next_ = d;
d->next_ = e;

kthToLastNode(2, a);
// returns the node with value 4 (the 2nd to last node)

// Solution
// We can think of this two ways.

/* First approach: use the length of the list.
1 - walk down the whole list, counting nodes, to get the total listLength.
2 - subtract kk from the listLength to get the distance from the head node to the target node (the kth to last node).
3 - walk that distance from the head to arrive at the target node. */

LinkedListNode * kthToLastNode(size_t k, LinkedListNode* head)
{
    if (k < 1) {
        throw invalid_argument(
                "Impossible to find less than first to last node: "
                + to_string(k));
    }

    // STEP 1: get the length of the list
    // start at 1, not 0
    // else we'd fail to count the head node!
    size_t listLength = 1;
    LinkedListNode* currentNode = head;

    // traverse the whole list,
    // counting all the nodes
    while (currentNode->next_) {
        currentNode = currentNode->next_;
        ++listLength;
    }

    // if k is greater than the length of the list, there can't
    // be a kth-to-last node, so we'll return an error!
    if (k > listLength) {
        throw invalid_argument(
                "k is larger than the length of the linked list: "
                + to_string(k));
    }

    // STEP 2: walk to the target node
    // calculate how far to go, from the head,
    // to get to the kth to last node
    size_t howFarToGo = listLength - k;

    currentNode = head;
    for (size_t i = 0; i < howFarToGo; ++i) {
        currentNode = currentNode->next_;
    }

    return currentNode;
}

/* Second approach: maintain a kk-wide "stick" in one walk down the list.
1 - Walk one pointer kk nodes from the head. Call it rightNode.
2 - Put another pointer at the head. Call it leftNode.
3 - Walk both pointers, at the same speed, towards the tail. This keeps a distance of kk between them.
4 - When rightNode hits the tail, leftNode is on the target (since it's kk nodes from the end of the list). */

LinkedListNode * kthToLastNode(size_t k, LinkedListNode* head)
{

    if (k < 1) {
        throw invalid_argument(
                "Impossible to find less than first to last node: "
                + to_string(k));
    }

    LinkedListNode* leftNode  = head;
    LinkedListNode* rightNode = head;

    // move rightNode to the kth node
    for (size_t i = 0; i < k - 1; ++i) {

        // but along the way, if a rightNode doesn't have a next,
        // then k is greater than the length of the list and there
        // can't be a kth-to-last node! we'll raise an error
        if (!rightNode->next_) {
            throw invalid_argument(
                    "k is larger than the length of the linked list: "
                    + to_string(k));
        }

        rightNode = rightNode->next_;
    }

    // starting with leftNode on the head,
    // move leftNode and rightNode down the list,
    // maintaining a distance of k between them,
    // until rightNode hits the end of the list
    while (rightNode->next_) {
        leftNode  = leftNode->next_;
        rightNode = rightNode->next_;
    }

    // since leftNode is k nodes behind rightNode,
    // leftNode is now the kth to last node!
    return leftNode;
}

// In either approach, make sure to check if k is greater than the length of the linked list! That's bad input, and we'll want to raise an error.

// Complexity
// Both approaches use O(n) time and O(1) space.
