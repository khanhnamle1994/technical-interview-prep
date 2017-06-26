// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and
// each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        int carry = (l1->val + l2->val) / 10;
        ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
        ListNode *tail = l3;
        l1 = l1->next;
        l2 = l2->next;

        while(l1 || l2 || carry)
        {
            int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
            ListNode *t  = new ListNode(sum % 10);
            carry = sum / 10;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            tail->next = t;
            tail = t;
        }

        return l3;
    }
};
