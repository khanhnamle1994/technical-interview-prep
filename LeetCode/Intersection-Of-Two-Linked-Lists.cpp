// Write a program to find the node at which the intersection of two singly linked lists begins.

/* For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
+ If the two linked lists have no intersection at all, return null.
+ The linked lists must retain their original structure after the function returns.
+ You may assume there are no cycles anywhere in the entire linked structure.
+ Your code should preferably run in O(n) time and use only O(1) memory. */

/* Analysis:
Consider the case that two list has equal length, the problem became so easy: only two pointers are needed.  Scan from the start of each
list, check if the node are the same. Problem solved !

However, just like the example showed in the question, we need to handle the case when the two list are not equal in length.  What to do
then?  Let's make them equal !
(1) Get the length of list A, say n_a.
(2) Get the length of list B, say n_b.
These two steps will take O(n) time. (n = n_a + n_b)
(3) Set two pointers. Make the pointer of longer list abs(n_a-n_b) steps forward.
(4) Scan the two list until find the intersection, or to the end of list.
This step will take O(n) time.

Totally, time complexity is O(n), space complexity is O(1). */

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
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     int n1 = 0; // length of headA
     int n2 = 0; // length of headB
     ListNode *a1 = headA;
     ListNode *a2 = headB;

     while(a1) {
       n1++;
       a1 = a1->next;
     }

     while(a2) {
       n2++;
       a2 = a2->next;
     }

     a1 = headA;
     a2 = headB;

     while (n1 > 0 && n2 > 0) {
       if(n1 > n2) {
         n1--;
         a1 = a1->next;
       }
       if(n2 > n1) {
         n2--;
         a2 = a2->next;
       }
       if(n2 == n1) {
         if(a1 == a2) {
           return a1;
         } else {
           a1 = a1->next;
           a2 = a2->next;
           n1--;
           n2--;
         }
       }
     }
     return NULL;
   }
 }
