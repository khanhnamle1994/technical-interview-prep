// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.

/* Analysis:
This is a classic question related to queue and stack. Let's review the stack and queue data structure, it is very easy to remember the
properties of those two data structures that:

Queue:  FIFO (First In First Out)
Stack: LIFO (Last In First Out)

This question asks to use queue to simulate stack. There are several ways to do so, here I just provide one of the solutions that utilizing
two queues. The basic idea is to swap the two queues every time when popping the element from stack. Queue 1 stores the stack top element,
Queue 2 stores the previous elements. Every time when pushing one element into stack, push queue 1's top in queue 2, and push the new
element in queue 1. Every time when popping the top element in stack, push the queue 1's top (only one element in this queue). Then push
n-1 elements from queue 2 to queue 1, where n is the total number of elements in queue 2. In other words, we left one element in queue 2
(this is the top element in the current stack), and push all the other elements into the empty queue (queue 1). Finally we swap queue 1
and queue 2. The stack is empty iff queue 1 and queue 2 are all empty. The top element is always the only element in queue 1.
*/

class Stack {
private:
  queue<int> q1;
  queue<int> q2;

public:
  Stack() {
    queue<int> q1, q2;
  }

  void push(int x) {
    q1.push(x);
    if(q1.size() == 1) {return;}
    int tmp = q1.front();
    q1.pop();
    q2.push(tmp);
  }

  void pop() {
    q1.pop();
    if(q2.size() == 0) { return; }
    for(int i = 0; i < q2.size() - 1; i++) {
      q1.push(q2.front());
      q2.pop();
    }
    queue<int> tmp;
    tmp = q1;
    q1 = q2;
    q2 = tmp;
  }

  int top() {
    return q1.front();
  }

  bool empty() {
    if(q1.size() == 0 && q2.size() == 0) {
      return true;
    } else {
      return false;
    }
  }
}
