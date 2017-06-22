// A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
// Complete the function provided in the editor below. It has one parameter: a pointer to a Node object named head that points to the
// head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list. If there is a cycle,
// return true; otherwise, return false.

// Note: If the list is empty, head will be null.

/*
A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if(head == NULL) {return false;}

    Node* slow = head;
    Node* fast = head->next;

    while(slow->next != NULL && fast->next != NULL) {
        if(slow == fast) {
            return true;
        }

        slow = slow->next;
        fast = fast->next->next;

    }
    return false;
}
