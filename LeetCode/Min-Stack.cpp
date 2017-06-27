/* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

class MinStack {
private:
  stack<int> s1;
  stack<int> s2;

public:
  void push(int x) {
    s1.push(x);
    if(s2.empty() || x <= getMin())
      s2.push(x);
  }

  void pop() {
    if(s1.top() == getMin())
      s2.pop();
    s1.pop();
  }

  int top() {
    return s1.top();
  }

  int getMin() {
    return s2.top();
  }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
