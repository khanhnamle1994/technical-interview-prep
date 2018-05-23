// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

/* Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseKGroup(ListNode* head, int k) {
  if(head == NULL || k == 1) return head;
  int num = 0;

  ListNode *preheader = new ListNode(-1);
  preheader->next = head;
  ListNode *cur = preheader, *nex, *pre = preheader;

  while(cur = cur->next)
      num++;
  while(num >= k) {
      cur = pre->next;
      nex = cur->next;
      for(int i = 1; i < k; ++i) {
          cur->next = nex->next;
          nex->next = pre->next;
          pre->next = nex;
          nex = cur->next;
      }
      pre = cur;
      num -= k;
  }
  return preheader->next;
}
