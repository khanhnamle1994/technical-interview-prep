// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

/*Analysis:

This problem can be viewed as two major steps:
    (1) Detect whether the loop exists in the linked list.
    (2) Find the loop start node if loop exists.

The (1) step can be easily solved using the slow&fast pointers. How to deal with step (2)?

Firstly let us assume the slow pointer (S) and fast pointer (F) start at the same place in a n node circle. S run t steps while F
can run 2t steps, we want to know what is t (where they meet) , then just solve:
t mod n = 2t mod n,  it is not hard to know that when t = n, they meet, that is the start of the circle.

For our problem, we can consider the time when S enter the loop for the 1st time, which we assume k step from the head. At this time,
the F is already in k step ahead in the loop. When will they meet next time?
Still solve the function:    t mod n = (k + 2t) mod n
Finally, we can find out: t = (n-k), S and F will meet, this is k steps before the start of the loop.

So, the Step (2) can be easily solved after Step (1):
Note that here S and F are not slow or fast pointers, but only regular pointers.
1. Set S to the head.
2. S = S -> next, F = F->next
3. output either one of the pointer until they meet.
*/

ListNode *detectCycle(ListNode *head) {
  if (!head) { return NULL; }
  ListNode *p = head;
  ListNode *q = head;

  while (head) {
    if (p->next != NULL) {
      p = p->next;
    } else {
      return NULL;
    }

    if (q->next != NULL && q->next->next != NULL) {
      q = q->next->next;
    } else {
      return NULL;
    }

    if (p == q) { // if find the loop, then looking for the loop start
      q = head;
      while (p != q) {
        p = p->next;
        q = q->next;
      }
      return p;
    }
  }
}
