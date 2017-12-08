// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which
// the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.

int minSubArrayLen(int s, vector<int>& nums) {
  int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
  for (int i = 0; i < n; i++) {
      sum += nums[i];
      while (sum >= s) {
          minlen = min(minlen, i - start + 1);
          sum -= nums[start++];
      }
  }
  return minlen == INT_MAX ? 0 : minlen;
}
