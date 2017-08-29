// Use the built-in stack class to implement a new class MaxStack with a function getMax() that returns the largest element
// in the stack. getMax() should not remove the item.

/* Solution:
We define two new stacks within our MaxStack class—stack_ holds all of our integers, and maxesStack_ holds our "maxima."
We use maxesStack_ to keep our max up to date in constant time as we push() and pop():

1/ Whenever we push() a new item, we check to see if it's greater than or equal to the current max, which is at the top of
maxesStack_. If it is, we also push() it onto maxesStack_.

2/ Whenever we pop(), we also pop() from the top of maxesStack if the item equals the top item in maxesStack_. */

class MaxStack
{
private:
  stack<int> stack_;
  stack<int> maxesStack_;

public:
  // Add a new item to the top of our stack. If the item is greater
  // than or equal to the last item in maxesStack, it's
  // the new max! So we'll add it to maxesStack.
  void push(int item)
  {
      stack_.push(item);
      if (maxesStack_.empty() || item >= maxesStack_.top()) {
          maxesStack_.push(item);
      }
  }

  // Remove and return the top item from our stack. If it equals
  // the top item in maxesStack, they must have been pushed in together.
  // So we'll pop it out of maxesStack too.
  int pop()
  {
      int item = stack_.top();
      stack_.pop();
      if (item == maxesStack_.top()) {
          maxesStack_.pop();
      }
      return item;
  }

  // The last item in maxesStack is the max item in our stack.
  int getMax() const
  {
      return maxesStack_.top();
  }
};

/* Complexity:
O(1) time for push(), pop(), and getMax(). O(m) additional space, where mm is the number of operations performed on the stack.

Notice that our time-efficient approach takes some additional space, while a lazy approach (simply walking through the stack to
find the max integer whenever getMax() is called) took no additional space. We've traded some space efficiency for time efficiency. */

/* What We Learned:
Notice how in the solution we're spending time on push() and pop() so we can save time on getMax(). That's because we chose to
optimize for the time cost of calls to getMax().

But we could've chosen to optimize for something else. For example, if we expected we'd be running push() and pop() frequently and
running getMax() rarely, we could have optimized for faster push() and pop() functions.

Sometimes the first step in algorithm design is deciding what we're optimizing for. Start by considering the expected characteristics
of the input. */
