// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

int search(vector<int>& nums, int target) {
  int n = nums.size();
  int mid = n / 2;
  int l = 0, r = n - 1;

  while (l <= r) {
    if (target < nums[mid]) {
      // case 1
      if (nums[l] <= nums[mid]) {
        if (target >= nums[l]) { // left side
          r = mid - 1;
          mid = (l + r) / 2;
        } else { // right side
          l = mid + 1;
          mid = (l + r) / 2;
        }
      } // case 2
      else { // left side
        r = mid - 1;
        mid = (l + r) / 2;
      }
    } else if (target > nums[mid]) {
      // case 2
      if (nums[r] >= nums[mid]) {
        if (nums[r] >= target) { // right side
          l = mid + 1;
          mid = (l + r) / 2;
        } else { // left side
          r = mid - 1;
          mid = (l + r) / 2;
        }
      } // case 1
      else { // right side
        l = mid + 1;
        mid = (l + r) / 2;
      }
    } else return mid;
  }
  return -1;
}
