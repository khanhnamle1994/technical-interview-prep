// Write a method that takes a sorted array and a key and returns the index of the first occurrence of that key in the array.

/* Solution: The fundamental idea of binary search is to maintain a set of candidate solutions. For the current problem, if we see the
element at index i equals k, although we do not know whether i is the first element equal to k, we do know that no subsequent elements
can be the first one. Therefore, we remove all elements with index i + 1 or more from the candidates. */

int SearchFirstOfK(const vector<int>& A, int k) {
  int left = 0, right = A.size() - 1, result = -1;
  // [left:right] is the candidate set
  while(left <= right) {
    int mid = left + ((right - left) / 2);
    if(A[mid] > k) {
      right = mid - 1;
    } else if(A[mid] == k) {
      result = mid;
      // nothing to the right of mid can be the first occurrence of k
      right = mid - 1;
    } else { // A[mid] < k
      left = mid + 1;
    }
  }
  return result;
}

// The time complexity is O(log n) - because each iteration reduces the size of the candidate set by half
