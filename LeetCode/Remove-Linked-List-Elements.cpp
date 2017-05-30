// Remove all elements from a linked list of integers that have value val.

// Example:
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Analysis:
// This is a fundamental pointer manipulation question.
// Just be careful with the case that removing 1st element. In the code below, a new pointer is assigned to link to the 1st element.

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
  ListNode* removeElements(ListNode* head, int val){
    if(!head) return NULL;
    ListNode *h = new ListNode(0);
    h->next = head;
    head = h;
    while(h->next){
      if(h->next->val == val){
        h->next = h->next->next;
      } else {
        h = h->next;
      }
    }
    return head->next;
  }
}
