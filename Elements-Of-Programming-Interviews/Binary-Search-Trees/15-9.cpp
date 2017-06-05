// Build a BST of minimum possible height from a sorted array

/* Solution: Let n be the length of the array. To achieve optimum balance we can make the element in the middle of the array, the [n/2]th
entry, the root, and recursively compute minimum height BSTs for the subarrays on either side of this entry. */

unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArray(const vector<int>& A) {
  return BuildMinHeightBSTFromSortedArrayHelper(A, 0, A.size());
}

// Build a min-height BST over the entries in A[start:end-1]
unique_ptr<BSTNode<int>> BuildMinHeightBSTFromSortedArrayHelper(const vector<int>& A, int start, int end) {
  if(start >= end) { return nullptr; }
  int mid = start + ((end - start) / 2);
  return make_unique<BSTNode<int>>(BSTNode<int> {A[mid], BuildMinHeightBSTFromSortedArrayHelper(A, start, mid),
    BuildMinHeightBSTFromSortedArrayHelper(A, mid + 1, end)});
}

// The time complexity T(n) satisfies the recurrence T(n) = 2T(n/2) + O(1), which solves to T(n) = O(n).
