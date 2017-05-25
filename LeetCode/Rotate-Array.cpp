// Rotate an array of n elements to the right by k steps.
// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note: Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

/* Analysis:
1st solution is to use a temp array.  Space O(n).
e.g. nums = [ 1 2 3 4 5 ], k=2
temp = [4 5 1 2 3]
num = temp

2nd solution is to rotate one position each time and do it k times. Space O(1), but it will exceed the time limit.
e.g. nums = [1 2 3 4 5], k=2
1st iteration:
      nums = [1 1 2 3 4] temp = 5, then nums = [5 1 2 3 4]
2nd iteration:
      nums = [5 5 1 2 3] temp = 4, nums = [4 5 1 2 3]

3rd solution is to rotate k steps once for an element. Space O(1).
e.g. nums = [1 2 3 4 5 6], k=2
1st iteration: starts from nums[i=0], keep rotate nums[i+k] until meet the start position
      nums = [5 2 1 4 3 6]
2nd iteration: starts from nums[i=1]
      nums = [5 6 1 2 3 4]
*/

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (nums == NULL || nums.size() <= 0 || k <= 0) return;
    k = k % nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }

  void reverse(vector<int>& nums, int i, int j) {
    if (i >= j) return;
    while (i < j) {
      swap(nums, i, j);
      i++;
      j--;
    }
  }

  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
}
