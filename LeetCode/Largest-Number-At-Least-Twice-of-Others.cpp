// In a given integer array nums, there is always exactly one largest element.

// Find whether the largest element in the array is at least twice as much as every other number in the array.

// If it is, return the index of the largest element, otherwise return -1.

/* Example 1:

Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.

Example 2:

Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1. */

int dominantIndex(vector<int>& nums) {
  int maxn = INT_MIN, idx = -1, sec = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > maxn) {
          sec = maxn;
          maxn = nums[i];
          idx = i;
      } else if(nums[i] > sec){
          sec = nums[i];
      }
  }
  return sec * 2 > maxn ? -1 : idx;
}
