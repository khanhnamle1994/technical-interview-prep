// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

/* Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

 // The idea is fairly straightforward: create an array accu that stores the accumulated sum for nums such that
 // accu[i] = nums[0] + ... + nums[i - 1] in the initializer of NumArray. Then just return accu[j + 1] - accu[i] in sumRange.

 class NumArray {
 public:
     NumArray(vector<int> nums) {
         accu.push_back(0);
         for (int num : nums)
            accu.push_back(accu.back() + num);
     }

     int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
     }

private:
    vector<int> accu;
 };
