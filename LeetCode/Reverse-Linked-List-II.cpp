// Reverse a linked list from position m to n. Do it in-place and in one-pass.

/* For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// The basic idea is as follows:

// (1) Create a new_head that points to head and use it to locate the immediate node before the m-th
// (notice that it is 1-indexed) node pre;

// (2) Set cur to be the immediate node after pre and at each time move the immediate node after cur
// (named move) to be the immediate node after pre. Repeat it for n - m times.

ListNode* reverseBetween(ListNode* head, int m, int n) {
  ListNode* new_head = new ListNode(0);
  new_head -> next = head;
  ListNode* pre = new_head;

  for (int i = 0; i < m - 1; i++)
          pre = pre -> next;
  ListNode* cur = pre -> next;

  for (int i = 0; i < n - m; i++) {
      ListNode* move = cur -> next;
      cur -> next = move -> next;
      move -> next = pre -> next;
      pre -> next = move;
  }
  return new_head -> next;
}
