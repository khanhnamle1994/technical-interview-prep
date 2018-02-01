// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the
// substring together. You may assume the given string consists of lowercase English letters only and its length will not
// exceed 10000.

/* Example 1:
Input: "abab"
Output: True

Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.) */

bool repeatedSubstringPattern(string s) {
  int i = 1, j = 0, n = s.size();
  vector<int> dp(n + 1, 0);
  while( i < s.size() ){
      if( s[i] == s[j] ) {
          dp[++i] = ++j;
      } else if( j == 0 ) {
          i++;
      } else {
          j = dp[j];
      }
  }
  return dp[n] && dp[n] % (n - dp[n]) == 0;
}

// First, we build the KMP table.
// 1. Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
// 2. Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
// 3. To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide
// (str.size()-last entry).
