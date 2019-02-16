/* You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

Example:

Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}
