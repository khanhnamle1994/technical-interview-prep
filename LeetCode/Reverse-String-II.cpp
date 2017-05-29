// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.
// If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then
// reverse the first k characters and left the other as original.

// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will be in the range [1, 10000]

class Solution {
public:
  string reverseStr(string s, int k) {
    for (int left = 0; left < s.size() - 1; left += 2 * k) {
      for (int i = left, j = min(left + k - 1, static_cast<int>(s.size()) - 1); i < j; ++i, --j){
        swap(s[i], s[j]);
      }
    }
    return s;
  }
}

// O(n) time, O(1) space
