// Implement a queue with 2 stacks. Your queue should have an enqueue and a dequeue function and it should be "first in first out" (FIFO).
// Optimize for the time cost of m function calls on your queue. These can be any mix of enqueue and dequeue calls.

// Assume you already have a stack implementation and it gives O(1) time push and pop.

/* Solution:
Let's call our stacks inStack and outStack.

For enqueue, we simply push the enqueued item onto inStack.

For dequeue on an empty outStack, the oldest item is at the bottom of inStack. So we dig to the bottom of inStack by pushing each item
one-by-one onto outStack until we reach the bottom item, which we return.

After moving everything from inStack to outStack, the item that was enqueued the 2nd longest ago (after the item we just returned) is
at the top of outStack, the item enqueued 3rd longest ago is just below it, etc. So to dequeue on a non-empty outStack, we simply return
the top item from outStack. */

class QueueTwoStacks
{
private:
  stack<int> inStack_;
  stack<int> outStack_;

public:
  void enqueue(int item)
  {
      inStack_.push(item);
  }

  int dequeue()
  {
      if (outStack_.empty()) {
          // Move items from inStack to outStack, reversing order
          while (!inStack_.empty()) {
              int newestInStackItem = inStack_.top();
              inStack_.pop();
              outStack_.push(newestInStackItem);
          }

          // If outStack is still empty, raise an error
          if (outStack_.empty()) {
              throw runtime_error("Can't dequeue from empty queue!");
          }
      }

      int result = outStack_.top();
      outStack_.pop();
      return result;
  }
};

/* Complexity:
Each enqueue is clearly O(1) time, and so is each dequeue when outStack_ has items. Dequeue on an empty outStack_ is order of the number
of items in inStack_ at that moment, which can vary significantly.

Notice that the more expensive a dequeue on an empty outStack_ is (that is, the more items we have to move from inStack_ to outStack_),
the more O(1)-time dequeues off of a non-empty outStack_ it wins us in the future. Once items are moved from inStack_ to outStack_, they
just sit there, ready to be dequeued in O(1) time. An item never moves "backwards" in our data structure.

We might guess that this "averages out" so that in a set of m enqueues and dequeues the total cost of all dequeues is actually just O(m).
To check this rigorously, we can use the accounting method, counting the time cost per item instead of per enqueue or dequeue.

So let's look at the worst case for a single item, which is the case where it is enqueued and then later dequeued. In this case, the item
enters inStack_ (costing 1 push), then later moves to outStack_ (costing 1 pop and 1 push), then later comes off outStack_ to get returned
(costing 1 pop).

Each of these 4 pushes and pops is O(1) time. So our total cost per item is O(1). Our m enqueue and dequeue operations put m or fewer items
into the system, giving a total runtime of O(m). */

/* What We Learned:
People often struggle with the runtime analysis for this one. The trick is to think of the cost per item passing through our queue, rather
than the cost per enqueue() and dequeue().

This trick generally comes in handy when you're looking at the time cost of not just one function call, but "m" function calls. */
