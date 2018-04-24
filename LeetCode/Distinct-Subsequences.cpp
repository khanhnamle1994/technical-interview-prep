// Given a string S and a string T, count the number of distinct subsequences of S which equals T.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

/* Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3

Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:

Input: S = "babgbag", T = "bag"
Output: 5

Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^ */

int numDistinct(string s, string t) {
  int m = t.length(), n = s.length();
  vector<int> cur(m + 1, 0);
  cur[0] = 1;
  for (int j = 1; j <= n; j++) {
      int pre = 1;
      for (int i = 1; i <= m; i++) {
          int temp = cur[i];
          cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? pre : 0);
          pre = temp;
      }
  }
  return cur[m];
}
