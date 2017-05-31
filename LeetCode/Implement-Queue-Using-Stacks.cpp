// Implement the following operations of a queue using stacks.

// push(x) -- Push element x to the back of queue.
// pop() -- Removes the element from in front of queue.
// peek() -- Get the front element.
// empty() -- Return whether the queue is empty.

/* Analysis:
This kind of problem usually requires more than one data structure to implement the other data structure. In this problem, two stacks are
enough to implement a queue.

The idea is keep push element into stack 1, then "pop" is called, put all the elements from stack 1 to stack 2. Then pop the top element
in stack 2.  If "pop" is called again, not stack 2 is not empty, just pop the top element is enough. If stack 2 is empty, put all the
elements in stack 1 to stack 2.  In short, stack 1 is used for "push", stack 2 is used for "pop" and "peek". We do the "move element
from stack1 to stack 2" only when stack 2 is empty and "pop" or "peek" is called. */

class Queue {
private:
  stack<int> st1;
  stack<int> st2;

public:
    // Push element x to the back of queue.
    void push(int x) {
        st1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!st2.empty()){
            st2.pop();
        }else{
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if (!st2.empty()){
            return st2.top();
        }else{
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (st1.empty() && st2.empty());
    }
};
