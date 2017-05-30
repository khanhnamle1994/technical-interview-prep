// Given a singly linked list and an integer k, write a program to remove the kth last element from the list. You cannot assume that it is
// possible to record the length of the list.

/* Solution:
A brute-force approach is to compute the length with one pass, and then use that to determine which node to delete in a second pass. A
drawback of this approach is that it entails two passes over the data, which is slow, e.g., if traversing the list entails disc accesses.

We use 2 iterators to traverse the list. The 1st iterator is advanced by k steps, and then the 2 iterators advance in tandem. When the 1st
iterator reaches the tail, the 2nd iterator is at the (k+1)th last node, and we can remove the kth node. */

shared_ptr<ListNode<int>> RemoveKthLast(const shared_ptr<ListNode<int>>& L, int k){
  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto first = dummy_head->next;
  while(k--) {
    first = first->next;
  }

  auto second = dummy_head;
  while(first) {
    second = second->next;
    first = first->next;
  }

  // second points to the (k+1)-th last node, deletes its successor
  second->next = second->next->next;
  return dummy_head->next;
}

// Time complexity is O(n) for list traversal and space complexity is O(1) as there are only 2 iterators
