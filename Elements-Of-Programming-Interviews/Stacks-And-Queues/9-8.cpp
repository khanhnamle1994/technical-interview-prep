// Implement a queue API using an array for storing elements. Your API should include a constructor function, which takes as argument the
// initial capacity of the queue, enqueue and dequeue functions, and a function which returns the number of elements stored. Implement
// dynamic resizing to support storing an arbitrarily large number of elements.

/* Solution:
A brute-force approach is to use an array, with the head always at index 0. An additional variable tracks the index of the tail element.
Enqueue has O(1) time complexity. However dequeue's time complexity is O(n), where n is the number of elements in the queue, since every
element has to be left-shifted to fill up the space created at index 0.

A better approach is to keep one more variable to track the head. This way, dequeue can also be performed in O(1) time. When performing an
enqueue into a full array, we need to resize the array. We cannot only resize, because this results in queue elements not appearing contiguously. */

class Queue {
public:
  explicit Queue(size_t capacity) : entries_(capacity) {}

  void Enqueue(int x) {
    if(num_queue_elements == entries_.size()) { // needs to resize
      // makes the queue elements appear consecutively
      rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
      head_ = 0, tail_ = num_queue_elements; // resets head and tail
      entries_.resize(entries_.size() * kScaleFactor);
    }

    entries_[tail_] = x;
    tail_ = (tail_ + 1) % entries_.size();
    num_queue_elements++;
  }

  int Dequeue() {
    if(!num_queue_elements) {
      throw length_error("empty queue");
    }
    num_queue_elements--;
    int ret = entries_[head_];
    head_ = (head_ + 1) % entries_.size();
    return ret;
  }

  size_t size() const {
    return num_queue_elements;
  }

private:
  const int kScaleFactor = 2;
  size_t head_ = 0, tail_ = 0, num_queue_elements = 0;
  vector<int> entries_;
}

// The time complexity of dequeue is O(1), and the amortized time complexity of enqueue is O(1)
