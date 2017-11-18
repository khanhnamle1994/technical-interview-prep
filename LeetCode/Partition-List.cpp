// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

/* For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* partition(ListNode* head, int x) {
  ListNode node1(0), node2(0);
  ListNode *p1 = &node1, *p2 = &node2;

  while (head) {
    if (head->val < x)
        p1 = p1->next = head;
    else
        p2 = p2->next = head;
    head = head->next;
  }
  p2->next = NULL;
  p1->next = node2.next;

  return node1.next;
}
