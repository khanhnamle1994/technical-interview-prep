// Write a program which takes as input 2 sorted arrays of integers, and updates the first to the combined entries of the 2 arrays in sorted
// order. Assume the first array has enough empty entries at its end to hold the result.

/* Solution:
We do have spare space at the end of the first array. We take advantage of this by filling the first array from its end. The last element
in the result will be written to index m + n - 1.

Note that we will never overwrite an entry in the first array that has not already been processed. The reason is that even if every entry
of the second array is larger than each element of the first array, all elements of the second array will fill up indices m to m + n - 1
inclusive, which does not conflict with entries stored in the first array. */

void MergeTwoSortedArray(int A[], int m, int B[], int n) {
  int a = m - 1, b = n - 1, write_idx = m + n - 1;
  while (a >= 0 && b >= 0) {
    A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
  }
  while (b >= 0) {
    A[write_idx--] = B[b--];
  }
}

// The time complexity is O(m + n). It uses O(1) additional space.
