// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element. You may assume no duplicate exists in the array.

/* Analysis:

In a sorted array, the minimum is the first element. Now the array has been rotated, so we need to search the minimum element.
Binary search is usually a efficient way dealing with such problems where the "sub" array has the similar structure of the
"parent" array.

In this problem, there is only 1 rotation, so that there are only limited cases when we split the array using the mid-element:
 1. the right part is ordered (A[mid] < A[ed])
 2. the right  part is unordered (A[mid] > A[ed])
 Some might say that what about the left part of the array? Note that there is only 1 rotation, which indicates that if right
 part is unordered, the left part of array must be ordered.

Considering the above two cases, finding the minimum is now becoming a simple binary search with slight modifications.
Details can be seen in the following code. */

void binarysearch(vector<int>& nums, int start, int end, int & result) {
  if (start > end) { return; }
  else {
    int mid = start + (end - start) / 2; // get middle index
    if (nums[mid] < nums[end]) { // the right part is ordered
      result = min(result, nums[mid]); // get the minimum in the right part
      binarysearch(nums, start, mid - 1, result); // search the left part
    } else { // the right part is unordered
      result = min(result, nums[start]); // get the minimum in the left part
      binarysearch(nums, mid + 1, end, result); // search the right part
    }
  }
}

int findMin(vector<int>& nums) {
  int n = nums.size();
  int result = nums[0];
  binarysearch(nums, 0, n - 1, result);
  return result;
}
