// Implement an algorithm to find the nth to last element of a singly linked list

#include <iostream>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node* init(int a[], int n){
	node *head, *p;
	for(int i=0; i < n; ++i){
	node *nd = new node();
	nd->data = a[i];
	if(i==0){
		head = p = nd;
		continue;
	}
	p->next = nd;
	p = nd;
	}
	return head;
}

/* This question is how do we find the penultimate element in a single list?
Because it is a single list, so we can not from the last element count, then the
number of n get the answer. But this is the most intuitive way of thinking is
clearly right, then we have no way through other ways, from the last element of
the number of n to get the answer we want it.

This order of upside down ideas allows us to think of a data structure: stack.

If we traverse the single list, the elements of which stack, and then the elements
one by one out of the stack. So, the first n of the elements of the stack is what
we want.

Do we need to explicitly use the stack so a structure to do this problem? Is the
answer yes. See the stack, we should think of recursion, it is a natural way to
use the stack. So, the first solution is recursive, letting the stack help us
from the last element of the list.

The idea is very simple, if the pointer to the list is not empty, it is constantly
recursive. When the pointer is empty when the return of the return, the process
n by 1, directly equal to 1, you can remove the current elements of the stack.
The code is as follows: */

node *pp;
int nn;
void findNthToLast1(node *head) {
  if(head == NULL) return;
  findNthToLast1(head->next);
  if(nn == 1) pp = head;
  -nn;
}

/* Recursive feature is to understand the direct, the code is short. So, a lot of
recursive code looks very beautiful. In addition to recursion, this topic there
are other ways to do it? The answer is still there. Although we can not move
forward from the last element of a single list, but if we maintain two pointers,
the distance between them is n. Then I move the two pointers synchronously on
this single list, keeping their distance constant. So, when the second pointer
is empty, the first pointer is the request. Very tricky way to solve this problem
very beautifully. The code is as follows: */

node* findNthToLast(node *head, int n) {
  if(head == NULL || n < 1) return NULL;
  while(n > 0 && q) {
    q = q->next;
    n--;
  }
  if (n > 0) return NULL;
  while(q) {
    p = p->next;
    q = q->next;
  }
  return p;
}

int main(){
	int n = 10;
	int a[] = { 9, 2, 1, 3, 5, 6, 2, 6, 3, 1 };
	node *head = init(a, n);
	node *p = findNthToLast(head, 6);
	if(p) {
    cout<<p->data<<endl;
	} else {
    cout << "the length of link is not long enough" << endl;
  }
	nn = 6;
	findNthToLast1(head);
	if(pp) {
    cout << pp->data << endl;
  }
	return 0;
}
