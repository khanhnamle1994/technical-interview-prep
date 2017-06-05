// Write a program which takes as input a very long sequence of numbers and prints the numbers in sorted order. Each number is at most k
// away from its correctly sorted order.

/* Solution:
The brute-force approach is to put the sequence in an array, sort it, and then print it. The time complexity is O(n logn), where n is the
length of the input sequence. The space complexity is O(n).

We can do better by taking advantage of the almost-sorted property. Specifically, after we have read k + 1 numbers, the smallest number
in that group must be smaller than all following numbers. To solve this problem in the general setting, we need to store k + 1 numbers
and want to be able to efficiently extract the minimum number and add a new number. A min-heap is exactly what we need. We add the first
k numbers to a min-heap. Now, we add additional numbers to the min-heap and extract the minimum from the heap. */

void SortApproximatelySortedData(istringstream* sequence, int k) {
  priority_queue<int, vector<int>, greater<>> min_heap;
  // Adds the first k elements into min_heap. Stop if there are fewer than k elements
  int x;
  for(int i = 0; i < k && *sequence >> x; i++) {
    min_heap.push(x);
  }

  // For every new element, add it to min_heap and extract the smallest
  while(*sequence >> x) {
    min_heap.push(x);
    cout << min_heap.top() << endl;
    min_heap.pop();
  }

  // Sequence is exhausted, iteratively extracts the remaining elements
  while(!min_heap.empty()) {
    cout << min_heap.top() << endl;
    min_heap.pop();
  }
}

// The time complexity is O(n log k). The space complexity is O(k).
