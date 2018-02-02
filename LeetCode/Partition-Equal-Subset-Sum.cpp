// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that
// the sum of elements in both subsets is equal.

/* Example 1:

Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.*/

bool canPartition(vector<int>& nums) {
  bitset<10001> bits(1);
  int sum = accumulate(nums.begin(), nums.end(), 0);
  for (auto n : nums) bits |= bits << n;
  return !(sum & 1) && bits[sum >> 1];
}
