// Write a program which takes a singly linked list L and two integers s and f as arguments, and reverses the order of the nodes from the
// sth node to fth node, inclusive. The numbering begins at 1, the head node is the first node. Do not allocate additional nodes

/* Solution:
The direct approach is to extract the sublist, reverse it, and splice it back in. The drawback for this approach is that it requires 2
passes over the sublist.

The update can be performed with a single pass by combining the identification of the sublist with its reversal. We identify the start of
sublist by using an iteration to get the sth node and its predecessor. Once we reach the sth node, we start the reversing process and keep
counting. When we reach the fth node, we stop the reversion process and link the reverted section with the unreverted sections. */

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start, int finish) {
  if(start == finish) {
    // No need to reverse since start == finish
    return L;
  }

  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;
  int k = 1;
  while (k++ < start) {
    sublist_head = sublist_head->next;
  }

  // Reverses sublist
  auto sublist_iter = sublist_head->next;
  while(start++ < finish) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
  }
  return dummy_head->next;
}

// Time complexity is dominated by the search for the fth node, i.e., O(f)
