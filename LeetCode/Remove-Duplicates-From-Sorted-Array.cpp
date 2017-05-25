// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.

// For example, given input array nums = [1,1,2], your function should return length = 2, with the first two elements of nums
// being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int last = 0, i, len = nums.size();
    if (!len) return 0;
    for (i = 0; i < len; i++) {
      if (nums[i] !- nums[last])
        nums[last++] = nums[i];
    }
    return last + 1;
  }
}
