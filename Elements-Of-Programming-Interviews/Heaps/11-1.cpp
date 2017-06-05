// Write a program that takes as input a set of sorted sequence and computes the union of these sequences as a sorted sequence. For example,
// if the input is <3, 5, 7>, <0, 6>, and <0, 6, 28>, then the output is <0, 0, 3, 5, 6, 6, 7, 28>

/* Solution:
A brute force approach is to concatenate these seqeunces into a single array and then sort it. The time complexity is O(n log n), assuming
there are n elements in total. The brute-force approach does not use the fact that the individual sequences are sorted. We can take advantage
of this fact by restricting our attention to the first remaining element in each sequence. Specifically, we repeatedly pick the smallest
element amongst the first element of each of the remaining part of each of the sequences.

A min-heap is ideal for maintaining a collection of elements when we need to add arbitrary values and extract the smallest element. */

struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd& that) const {
    return *current > *that.current;
  }

  vector<int>::const_iterator current;
  vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
  priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<>> min_heap;
  for (const vector<int>& sorted_array : sorted_arrays) {
    if(!sorted_array.empty()) {
      min_heap.emplace(IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()});
    }
  }

  vector<int> result;
  while(!min_heap.empty()) {
    auto smallest_array = min_heap.top();
    min_heap.pop();
    if(smallest_array.current != smallest_array.end) {
      result.emplace_back(*smallest_array.current);
      min_heap.emplace(IteratorCurrentAndEnd{next(smallest_array.current), smallest_array.end});
    }
  }
  return result;
}

// Let k be the number of input sequences. Then there are no more than k elements in the min-heap. Both extract-min and insert take O(log k)
// time. Hence, we can do the merge in O(n log k) time. The space complexity is O(k) beyond the space needed to write the final result.
// In particular, if the data comes from files and is written to a file, instead of arrays, we would need only O(k) additional storage.
