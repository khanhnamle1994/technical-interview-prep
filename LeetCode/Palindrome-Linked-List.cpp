// Given a singly linked list, determine if it is a palindrome.
// Follow up: Could you do it in O(n) time and O(1) space?

/* Analysis:

In order to satisfy the O(n) time and O(1) space requirements, we have to consider in-place check/modify the linked list.  Look at the
definition of palindrome, it is easily to find out for a palindrome, if we reverse the second half of the list, the first half and second
half are identical.

OK, this is where we start to solve the problem. How about the complexity?
1. First we need to find the middle pointer of the list. It is pretty easy if you remember the slow and fast pointers.

2. If we can do the reversing in-place, the space we need are only several temporary pointers. If you remember the previous questions,
you can easily reverse the list.

The basic idea is shown here by an simple example:
Original list: 1->2->3->4->5
We can have a header pointer: head->1->2->3->4->5
Each time, move current pointer to the first place (which is after head pointer).
head->2->1->3->4->5
head->3->2->1->4->5
head->4->3->2->1->5
head->5->4->3->2->1
Done

3. The reversing step is of O(n) time, then checking two halves will only take O(n), so the overall time complexity is O(n). */

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
  void reverse_list(ListNode** head_ref) {
    ListNode* head = *head_ref;
    ListNode* p = head->next;
    while(p && p->next) {
      ListNode* tmp = p->next;
      p->next = p->next->next;
      tmp->next = head->next;
      head->next = tmp;
    }
    *head_ref = head;
  }

  bool isPalindrome(ListNode* head) {
    // Get middle pointer p1
    ListNode* p1 = new ListNode(0);
    p1->next = head;
    ListNode* p2 = p1;
    while(p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    // Reverse second half list
    reverse_list(&p1);

    // Check palindrome
    p1 = p1->next;
    p2 = head;
    while(p1) {
      if(p1->val != p2->val) {
        return false;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return true;
  }
}
