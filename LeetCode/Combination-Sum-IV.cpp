// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations
// that add up to a positive integer target.

/* Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7. */

int combinationSum4(vector<int>& nums, int target) {
  vector<int> result(target + 1);
  result[0] = 1;

  for (int i = 1; i <= target; ++i) {
      for (int x : nums) {
          if (i >= x) {
              result[i] += result[i - x];
          }
      }
  }
  return result[target];
}
