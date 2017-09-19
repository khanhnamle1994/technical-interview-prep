// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
// Find the two elements that appear only once.
// For example:
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

/*
1. assume that A and B are the two elements which we want to find;
2. use XOR for all elements,the result is : r = A^B,we just need to distinguish A from B next step;
3. if we can find a bit '1' in r,then the bit in corresponding position in A and B must be different.
We can use {last = r & (~(r-1))} to get the last bit 1 int r;
4. we use last to divide all numbers into two groups,then A and B must fall into the two distrinct groups.
XOR elements in eash group,get the A and B.
*/

vector<int> singleNumber(vector<int>& nums) {
  int r = 0, n = nums.size(), i = 0, last = 0;
  vector<int> ret(2, 0);

  for (i = 0; i < n; i++) {
    r ^= nums[i];
  }

  last = r & (~(r - 1));
  for (i = 0; i < n; i++) {
    if ((last & nums[i]) != 0) {
      ret[0] ^= nums[i];
    } else {
      ret[1] ^= nums[i];
    }
  }

  return ret;
}
