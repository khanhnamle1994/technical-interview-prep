// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

/* Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False */

bool checkInclusion(string s1, string s2) {
  int s1s = s1.size();
  int s2s = s2.size();
  int start = 0, cnt = 0, arr[26] = {};

  for (auto l : s1) {
    ++arr[l - 'a'];
  }

  for (auto i = 0; i < s2s && cnt < s1s; ++i) {
      if (arr[s2[i] - 'a'] > 0) {
        --arr[s2[i] - 'a'];
        ++cnt;
      }
      else while (s2[start++] != s2[i]) {
        ++arr[s2[start - 1] - 'a'];
        --cnt;
      }
  }
  return cnt == s1s;
}
