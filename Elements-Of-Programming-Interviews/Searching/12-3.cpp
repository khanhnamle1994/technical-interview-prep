// Design an O(log n) algorithm for finding the position of the smallest element in a cyclically sorted array. Assume all elements are distinct.

/* Solution:
A brute force approach is to iterate through the array, comparing the running minimum with the current entry. The time complexity is O(n),
where n is the length of the array. It does not take advantage of the special properties of the array, A.

For example, for any m, if A[m] > A[n - 1], then the minimum value must be an index in the range [m + 1, n - 1]. Conversely, if A[m] < A[n - 1],
then no index in the range [m + 1, n - 1] can be the index of the minimum value. Note that it is not possible for A[m] = A[n - 1], since
it is given that all elements are distinct. */

int SearchSmallest(const vector<int>& A) {
  int left = 0, right = A.size() - 1;
  while(left < right) {
    int mid = left + ((right - left) / 2);
    if(A[mid] > A[right]) {
      // Minimum must be in [mid + 1 : right]
      left = mid + 1;
    } else { // A[mid] < A[right]
      // Minimum cannot be in [mid + 1 : right] so it must be in [left : mid]
      right = mid;
    }
  }
  // Loop ends when left == right
  return left;
}

// The time complexity is the same as that of binary search, namely O(log n)
