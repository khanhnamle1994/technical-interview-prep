// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

// You need to find the shortest such subarray and output its length.

/* Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order. */

int findUnsortedSubarray(vector<int>& nums) {
  int shortest = 0;
  int left = 0, right = nums.size() - 1;

  while (left < nums.size() - 1 && nums[left] <= nums[left + 1]) {
    left++;
  }
  while (right > 0 && nums[right] >= nums[right - 1]) {
    right--;
  };

  if (right > left) {
      int vmin = INT_MAX, vmax = INT_MIN;
      for (int i = left; i <= right; ++i) {
          if (nums[i] > vmax) {
              vmax = nums[i];
          }
          if (nums[i] < vmin) {
              vmin = nums[i];
          }
      }

      while (left >= 0 && nums[left] > vmin) {
        left--;
      };
      while (right < nums.size() && nums[right] < vmax) {
        right++;
      };

      shortest = right - left - 1;
  }

  return shortest;
}
