// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate
// number must exist. Assume that there is only one duplicate number, find the duplicate one.

/* Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once. */

// 2 Pointers Method with O(n) time complexity
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        slow = nums[0];
        fast = nums[nums[0]];

        while (slow != fast) {
          slow = nums[slow];
          fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast) {
          slow = nums[slow];
          fast = nums[fast];
        }

        return slow;
    }
};

// Binary Search Method with O(n log n) time complexity
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int left, right;
    left = 1;
    right = nums.size();

    while(left <= right) {
      int mid = left + (right - left)/2;

      // get count of num <= mid
      int count = 0;
      for(const auto& num : nums) {
        if(num <= mid) {
          count++;
        }
      }
      if(count > mid) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
}
