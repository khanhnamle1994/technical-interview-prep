// Write a program that takes the head of a singly linked list and returns null if there does not exist a cycle, and the node at the start
// of the cycle, if a cycle is present.

/* Solution
This problem has several solutions. If space is not an issue, the simplest approach is to explore nodes via the next field starting from
the head and storing visited nodes in a hash table - a cycle exists if and only if we visit a node already in the hash table. If no cycle
exists, the search ends at the tail (often represented by having the next field set to null). This solution requires O(n) space, where n
is the number of nodes in the list.

A brute-force approach that does not use additional storage and does not modify the list is to traverse the list in 2 loops - the outer
loop traverses the nodes one-by-one, and the inner loop starts from the head, and traverses as many nodes as the outer loop has gone through
so far. If the node being visited by the outer loop is visited twice, a loop has been detected. This approach has O(n^2) time complexity.

This idea can be made to work in linear time - use a slow iterator and a fast iterator to traverse the list. In each iteration, advance the
slow iterator by one and the fast iterator by two. The list has a cycle if and only if the two iterators meet. The reasoning is as follows:
if the fast iterator jumps over the slow iterator, the slow iterator will equal the fast iterator in the next step.

Now, assuming that we have detected a cycle using the above method, we can find the start of the cycle, by first calculating the cycle
length C. Once we know there is a cycle, and we have a node on it, it is trivial to compute the cycle length. To find the first node on the
cycle, we use two iterators, one of which is C ahead of the other. We advance them in tandem, and when they meet, that node must be the first
node on the cycle. */

shared_ptr<ListNode<int>> HasCycle(const shared_ptr<ListNode<int>>& head) {
  shared_ptr<ListNode<int>> fast = head, slow = head;
  while (fast && fast->next) {
    slow = slow->next, fast = fast->next->next;

    if (slow == fast) {
      // There is a cycle, so let's calculate the cycle length
      int cycle_len = 0;
      do {
        cycle_len++;
        fast = fast->next;
      } while (slow != fast);

      // Finds the start of the cycle
      auto cycle_len_advanced_iter = head;
      while (cycle_len--) {
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }
      auto iter = head;

      // Both iterators advance in tandem
      while (iter != cycle_len_advanced_iter) {
        iter = iter->next;
        cycle_len_advanced_iter = cycle_len_advanced_iter->next;
      }
      return iter; // iter is the start of cycle
    }
  }
  return nullptr; // no cycle
}

// Let F be the number of nodes to the start of the cycle, C the number of nodes on the cycle, and n the total number of nodes. Then the
// time complexity is O(F) + O(C) = O(n) - O(F) for both pointers to reach the cycle, and O(C) for them to overlap once the slower one
// enters the cycle.
