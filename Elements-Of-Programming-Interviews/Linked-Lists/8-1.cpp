// Write a program that takes two lists, assumed to be sorted, and returns their merge. The only field your program can change in a node is
// its next field.

/* Solution:
A naive approach is to append the 2 lists together and sort the resulting list. The drawback of this approach is that it does not use the
fact that the initial lists are sorted. The time complexity is that of sorting, which is O((n+m)log(n+m)), where n and m are the lengths
of each of the two input lists.

A better approach is to traverse the 2 lists, always choosing the node containing the smaller key to continue traversing from. */

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1, shared_ptr<ListNode<int>> L2) {
  // Creates a placeholder for the result
  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>);
  auto tail = dummy_head;

  while (L1 && L2) {
    AppendNode(L1->data <= L2->data ? &L1 : &L2, &tail);
  }

  // Appends the remaining nodes of L1 and L2
  tail->next = L1 ? L1 : L2;
  return dummy_head->next;
}

void AppendNode(shared_ptr<ListNode<int>> *node, shared_ptr<ListNode<int>> *tail) {
  (*tail)->next = *node;
  *tail = *node; // Updates tail
  *node = (*node)->next;
}

// The worst-case corresponds to the case when the lists are of comparable length, so the time complexity is O(n+m). Since we reuse the
// existing nodes, the space complexity is O(1).
