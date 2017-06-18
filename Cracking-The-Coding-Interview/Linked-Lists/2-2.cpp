// Implement an algorithm to find the nth to last element of a singly linked list

#include <iostream>
using namespace std;

typedef struct node{
    int val;
    node *next;
} node;

node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
        node *nd = new node();
        nd->val = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}

/* Solution to finding the nth to last element in a linked list using iteration:
- pntr1 and pntr2 start out by both pointing to the head node
- pntr2 is then advanced n-1 nodes.  pntr1 is still pointing to the head. After
this, we keep advancing pntr2 by one node and pntr 1 is also advanced by one node
- Once pntr2 is equal to null we know we  have reached the last node and pntr1
now points to the nth to last node, and we can return our answer as the node
that pntr1 is pointing to. */

node* findNthToLast(node * head, int n) {
	if(n < 1 || head == NULL) return NULL;
	node **ptr1 = &head;
	node *ptr2 = head;

	// advance ptr2 by n-1 nodes
	for(int i = 0; i < n - 1; i++) {
		if(ptr2 == NULL) {
		 /* this is an error condition to check to see if the linked list is less than
		 n nodes long, in which case we just return null indicating an error */
		 return NULL;
	 } else { // go to next node
		 ptr2 = ptr2->next;
	 }
	}

	/* Now, keep going until you hit a null node, and then ptr2 reached the end,
	and ptr1 will be pointing to the nth from last node */
	while(ptr2->next) {
		ptr1 = &((*ptr1)->next);
		ptr2 = ptr2->next;
	}
	
  return *ptr1;
}

int main(){
	int n = 10;
	int a[] = { 9, 2, 1, 3, 5, 6, 2, 6, 3, 1 };
	node *head = init(a, n);
	node *p = findNthToLast(head, 2);

	if(p) {
    cout << p->val << endl;
	} else {
    cout << "the length of link is not long enough" << endl;
  }

	return 0;
}
