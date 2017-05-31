// Design a stack that includes a max operation, in addition to push and pop. The max method should return the maximum value stored in stack

/* Solution:
The simplest way to implement a max operation is to consider each element in the stack by iterating through the underlying array for an
array-based stack. The time complexity is O(n) and the space complexity is O(1), where n is the number of elements currently in the stack.

The time complexity can be reduced to O(log n) using auxiliary data structures, specifically, a heap or BST, and a hash table. The space
complexity increases to O(n) and the code is quite complex.

Suppose we use a single auxiliary variable, M, to record the element that is maximum in the stack. Updating M on pushes is easy: M = max(M, e),
where e is the element being pushed. However, updating M on pop is very time consuming. If M is the element being popped, we have no way
of knowing what the maximum remaining element is, and are forced to consider all the remaining elements.

We can dramatically improve on the time complexity of popping by caching, in essence, trading time for space. Specifically, for each entry
in the stack, we cache the maximum stored at or below that entry. Now when we pop, we evict the corresponding cached value. */

class Stack {
public:
  bool Empty() const { return element_with_cached_max_.empty(); }

  int Max() const {
    if(Empty()) {
      throw length_error("Max(): empty stack");
    }
    return element_with_cached_max_.top().max;
  }

  int Pop() {
    if(Empty()) {
      throw length_error("Pop(): empty stack");
    }
    int pop_element = element_with_cached_max_.top().element;
    element_with_cached_max_.pop();
    return pop_element;
  }

  void Push(int x) {
    element_with_cached_max_.emplace(ElementWithCacheMax{x, max(x, Empty() ? x : Max())});
  }

private:
  struct ElementWithCacheMax {
    int element, max;
  };
  stack<ElementWithCacheMax> element_with_cached_max_;
}

// Each of the specified methods has time complexity O(1). The additional space complexity is O(n), regardless of the stored keys.

/* We can improve on the best-case space needed by observing that if an element e being pushed is smaller than the maximum element already in
the stack, then e can never be the maximum, so we do not need to record it. We cannot store the sequence of maximum values in a separate
stack because of the possibility of duplicates. We resolve this by additionally recording the number of occurrences of each maximum value. */

class Stack {
public:
  bool Empty() const { return element_.empty(); }

  int Max() const {
    if(Empty()) {
      throw length_error("Max(): empty stack");
    }
    return cached_max_with_count_.top().max;
  }

  int Pop() {
    if(Empty()) {
      throw length_error("Pop(): empty stack");
    }
    int pop_element = element_.top();
    element_.pop();
    const int current_max = cached_max_with_count_.top().max;
    if(pop_element == current_max) {
      int& max_frequency = cached_max_with_count_.top().count;
      max_frequency--;
      if(max_frequency == 0) {
        cached_max_with_count_.pop();
      }
    }
    return pop_element;
  }

  void Push(int x) {
    element_.emplace(x);
    if(cached_max_with_count_.empty()) {
      cached_max_with_count_.emplace(MaxWithCount{x, 1});
    } else {
      const int current_max = cached_max_with_count_.top().max;
      if(x == current_max) {
        int& max_frequency = cached_max_with_count_.top().count;
        max_frequency++;
      } else if(x > current_max) {
        cached_max_with_count_.emplace(MaxWithCount{x, 1});
      }
    }
  }

private:
  stack<int> element_;
  struct MaxWithCount {
    int max, count;
  };
  stack<MaxWithCount> cached_max_with_count_;
}

// The worst case additional space complexity is O(n), which occurs when each key pushed is greater than all keys in the primary stack.
// However, when the number of distinct keys is small, or the maximum changes infrequently, the additional space complexity is less, O(1)
// in the best case. The time complexity for each specified method is still O(1).
