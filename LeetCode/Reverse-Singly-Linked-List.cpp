// Reverse a singly linked list.
// A linked list can be reversed either iteratively or recursively. Could you implement both?

/* Analysis:
Classic problem. There are multiple algorithms to reverse the linked list.

To illustrate the process, say we have the linked list:
  1->2->3->4->5->null
head

In order to reverse it, we define a new pointer:
newhead->null

Iterate the original list, each time insert the node to the start of the new linked list:
1. newhead->1->null
2. newhead->2->1->null
...
5 newhead->5->4->3->2->1->null

Then just return newhead->next. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution {
 public:
   ListNode* reverseList(ListNode* head) {
     ListNode* newhead = new ListNode(0);
     while(head) {
       ListNode* tmp = newhead->next;
       newhead->next = head;
       head = head->next;
       newhead->next->next = tmp;
     }
     return newhead->next;
   }
 }
