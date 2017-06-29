// Reverse a singly linked list

/* Definition for singly linked list
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
*/

// Iterative Solution
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* pre = NULL;
    while(head) {
      ListNode* next = head->next;
      head->next = pre;
      pre = head;
      head = next;
    }
    return pre;
  }
};

// Recursive Solution: The basic idea of this recursive solution is to reverse all the following nodes after head. Then we need to
// set head to the final node in the reversed list. We simply set its next node in the original (head->next) to point to it and set
// its next to be NULL
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(!head || !(head->next)) return head;
    ListNode* node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
  }
};
