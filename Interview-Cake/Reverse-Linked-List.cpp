// Write a function for reversing a linked list. ↴ Do it in-place. ↴
// Your function will have one input: the head of the list.
// Your function should return the new head of the list.

// Here's a sample linked list node class:

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

/* Breakdown
Our first thought might be to build our reversed list "from the beginning," starting with the head of the final reversed linked list.

The head of the reversed list will be the tail of the input list. To get to that node we'll have to walk through the whole list once
(O(n) time). And that's just to get started.

That seems inefficient. Can we reverse the list while making just one walk from head to tail of the input list?

We can reverse the list by changing the next_ pointer of each node. Where should each node's next_ pointer...point?

Each node's next_ pointer should point to the previous node.

How can we move each node's next_ pointer to its previous node in one pass from head to tail of our current list? */

/* Solution
In one pass from head to tail of our input list, we point each node's next_ pointer to the previous item.

The order of operations is important here! We're careful to copy current->next_ into next_ before setting current->next_ to previous.
Otherwise "stepping forward" at the end could actually mean stepping back to previous! */

LinkedListNode * reverse(LinkedListNode* headOfList)
{
  LinkedListNode* current = headOfList;
  LinkedListNode* previous = nullptr;
  LinkedListNode* nextNode = nullptr;

  // until we have 'fallen off' the end of the list
  while (current) {

      // copy a pointer to the next element
      // before we overwrite current.next
      nextNode = current->next_;

      // reverse the 'next' pointer
      current->next_ = previous;

      // step forward in the list
      previous = current;
      current = nextNode;
  }

  return previous;
}

// We return previous because when we exit the list, current is nullptr. Which means that the last node we visited—previous—was the tail
// of the original list, and thus the head of our reversed list.

// Complexity
// O(n) time and O(1) space. We pass over the list only once, and maintain a constant number of variables in memory.
