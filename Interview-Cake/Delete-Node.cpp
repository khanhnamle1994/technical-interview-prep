// Delete a node from a singly-linked list, given only a variable pointing to that node.

// The input could, for example, be the variable b below:
class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode * next_;

    LinkedListNode(int value) :
        intValue_(value),
        next_(nullptr)
    {
    }
};

LinkedListNode* a = new LinkedListNode(1);
LinkedListNode* b = new LinkedListNode(2);
LinkedListNode* c = new LinkedListNode(3);

a->next_ = b;
b->next_ = c;

deleteNode(b);

// Solution
// We take intValue_ and next_ from the input node's next node and copy them into the input node. Now the input node's previous node effectively
// skips the input node's old value!

void deleteNode(LinkedListNode* nodeToDelete)
{
    // get the input node's next node, the one we want to skip to
    LinkedListNode* nextNode = nodeToDelete->next_;

    if (nextNode) {

        // replace the input node's value and pointer with the next
        // node's value and pointer. the previous node now effectively
        // skips over the input node
        nodeToDelete->intValue_ = nextNode->intValue_;
        nodeToDelete->next_  = nextNode->next_;
        delete nextNode;
    }
    else {
        // eep, we're trying to delete the last node!
        throw invalid_argument("Can't delete the last node with this technique!");
    }
}

// But be careful—there are some potential problems with this implementation:

// First, it doesn't work for deleting the last node in the list. We could change the node we're deleting to have a value of nullptr, but the
// second-to-last node's next_ pointer would still point to a node, even though it should be nullptr. This could work—we could treat this last,
// "deleted" node with value nullptr as a "dead node" or a "sentinel node," and adjust any node traversing code to stop traversing when it hits such a
// node. The trade-off there is we couldn't have non-dead nodes with values set to nullptr. Instead we chose to throw an exception in this case.

// Second, this technique can cause some unexpected side-effects. For example, let's say we call:

LinkedListNode a = new LinkedListNode(3);
LinkedListNode b = new LinkedListNode(8);
LinkedListNode c = new LinkedListNode(2);

a.next_ = b;
b.next_ = c;

deleteNode(b);

/* There are two potential side-effects:

1. Any references to the input node have now effectively been reassigned to its next_ node. In our example, we "deleted" the node assigned to the
variable b, but in actuality we just gave it a new value (2) and a new next_! If we had another pointer to b somewhere else in our code and we
were assuming it still had its old value (8), that could cause bugs.

2. If there are pointers to the input node's original next node, those pointers now point to a "dangling" node (a node that's no longer reachable
by walking down our list). In our example above, c is now dangling. If we changed c, we'd never encounter that new value by walking down our list
from the head to the tail.

// Complexity
// O(1) time and O(1) space.
