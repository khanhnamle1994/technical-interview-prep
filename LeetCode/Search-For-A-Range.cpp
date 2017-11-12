// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

/* For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. */

vector<int> searchRange(vector<int>& nums, int target) {
  auto bounds = equal_range(nums.begin(), nums.end(), target);
  if (bounds.first == bounds.second)
      return {-1, -1};
  return {bounds.first - nums.begin(), bounds.second - nums.begin() - 1};
}
