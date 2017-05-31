// Implement a queue given a library implementing stacks

/* Solution:
A straightforward implementation is to enqueue by pushing the element to be enqueued onto one stack. The element to be dequeued is then the
element at the bottom of this stack, which can be achieved by first popping all its elements and pushing them to another stack, then popping
the top of the second stack (which was the bottom-most element of the first stack), and finally popping the remaining elements back to the
first stack.

The primary problem with this approach is that every dequeue takes two pushes and two pops of every element: dequeue has O(n) time complexity,
where n is the number of stored elements. (Enqueue takes O(1) time)

The intuition for improving the time complexity of dequeue is that after we move elements from the first stack to the second stack, any
further dequeues are trivial, until the second stack is empty. This is true even if we need to enqueue, as long as we enqueue onto the first
stack. When the second stack becomes empty, and we need to perform a dequeue, we simply repeat the process of transferring from the first
stack to the second stack. In essence, we are using the first stack for enqueue and the second for dequeue. */

class Queue {
public:
  void Enqueue(int x) {
    enq_.emplace(x);
  }

  int Dequeue() {
    if(deq_.empty()) {
      while(!enq_.empty()) {
        // Transfers the elements in enq_ to deq_
        deq_.emplace(enq_.top());
        enq_.pop();
      }
    }

    if(deq_.empty()) { // deq_ is still empty
      throw length_error("empty queue");
    }

    int ret = deq_.top();
    deq_.pop();
    return ret;
  }
private:
  stack<int> enq_, deq_;
}

// This approach takes O(m) time for m operations, which can be seen from the fact that each element is pushed no more than twice and popped
// no more than twice.
