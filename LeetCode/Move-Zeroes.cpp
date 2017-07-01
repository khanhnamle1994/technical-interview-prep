// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

// A typical double pointer problems. Traverse the array using two pointers, a pointer value of 0 for the element, the other element
// point value is not 0, the process of traversal, a continuous exchange of the values ​​of two pointers.

class Solution {
public:
  void MoveZeroes(vector<int>& nums) {
    int none_zero_index;
    int zero_index;
    for (none_zero_index = 0, zero_index = 0; none_zero_index < nums.size() && zero_index < nums.size(); ) {
      if (nums[zero_index] != 0) {
        zero_index++;
        none_zero_index = zero_index;
        continue;
      }
      if (nums[none_zero_index] == 0) {
        none_zero_index++;
        continue;
      }
      int temp = nums[zero_index];
      nums[zero_index] = nums[none_zero_index];
      nums[none_zero_index] = temp;
      zero_index++;
      none_zero_index++;
    }
  }

  void moveZeroes(vector<int>& nums) {
        int last = 0;
        int cur = 0;
        while(cur < nums.size()) {
            if(nums[cur] != 0) {
                swap(nums[cur], nums[last]);
                last++;
            }
            cur++;
        }
  }
};
