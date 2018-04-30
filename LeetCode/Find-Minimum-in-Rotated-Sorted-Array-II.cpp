// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
// Find the minimum element.
// The array may contain duplicates.

/* Example 1:
Input: [1,3,5]
Output: 1

Example 2:
Input: [2,2,2,0,1]
Output: 0 */

int findMin(vector<int>& nums) {
  int lo = 0;
  int hi = nums.size() - 1;
  int mid = 0;

  while(lo < hi) {
      mid = lo + (hi - lo) / 2;

      if (nums[mid] > nums[hi]) {
          lo = mid + 1;
      }
      else if (nums[mid] < nums[hi]) {
          hi = mid;
      }
      else { // when nums[mid] and nums[hi] are same
          hi--;
      }
  }
  return nums[lo];
}
