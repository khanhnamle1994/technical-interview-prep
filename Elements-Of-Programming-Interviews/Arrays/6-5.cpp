// Write a program which takes as input a sorted array and updates it so that all duplicates have been removed and the remaining elements
// have been shifted left to fill the emptied indices. Return the number of valid elements.

// A brute-force algorithm uses O(1) additional space - iterate through A, testing if A[i] equals A[i+1], and, if so, shift all elements
// at and after i+2 to the left by one. When all entries are equal, the number of shifts is (n-1) + (n-2) + ... + 2 + 1, i.e., O(n^2),
// where n is the length of the array.

// The intuition behind achieving a better time complexity is to reduce the amount of shifting. Since the array is sorted, repeated
// elements must appear one-after-another, so we do not need an auxiliary data structure to check if an element has appeared already. We
// move just one element, rather than an entire subarray, and ensure that we move it just once.

int DeleteDuplicates(vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  if (A.empty()) { return 0; }
  int write_index = 1;
  for (int i = 1; i < A.size(); i++) {
    if (A[write_index - 1] != A[i]) {
      A[write_index++] = A[i];
    }
  }
  return write_index;
}

// O(n) time complexity and O(1) space complexity
