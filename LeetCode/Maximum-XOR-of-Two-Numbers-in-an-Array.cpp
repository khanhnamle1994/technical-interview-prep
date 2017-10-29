// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
// Could you do this in O(n) runtime?

/* Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28. */

int findMaximumXOR(vector<int>& nums) {
  int result = 0;

  for (int i = 31; i >= 0; --i) {
      result <<= 1;
      unordered_set<int> prefixes;
      for (const auto& n : nums) {
          prefixes.emplace(n >> i);
      }
      for (const auto& p : prefixes) {
          if (prefixes.count((result | 1) ^ p)) {
              ++result;
              break;
          }
      }
  }

  return result;
}
