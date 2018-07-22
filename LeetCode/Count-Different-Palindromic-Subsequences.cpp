// Given a string S, find the number of different non-empty palindromic subsequences in S, and return that number modulo 10^9 + 7.
// A subsequence of a string S is obtained by deleting 0 or more characters from S.
// A sequence is palindromic if it is equal to the sequence reversed.
// Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i for which A_i != B_i.

/* Example 1:

Input:
S = 'bccb'
Output: 6

Explanation:
The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.

Example 2:

Input:
S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
Output: 104860361

Explanation:
There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 10^9 + 7. */

int countPalindromicSubsequences(string s) {
  int md = 1000000007;
  int n = s.size();
  int dp[3][n][4];
  for (int len = 1; len <=n; ++len) {
      for (int i = 0; i + len <=n; ++i) for (int x = 0; x < 4; ++x)  {
          int &ans = dp[2][i][x];
          ans = 0;
          int j = i + len - 1;
          char c = 'a' + x;
          if (len == 1) ans = s[i] == c;
          else {
              if (s[i] != c) ans = dp[1][i+1][x];
              else if (s[j] != c) ans = dp[1][i][x];
              else {
                  ans = 2;
                  if (len > 2) for (int y = 0; y < 4;++y) {
                      ans += dp[0][i+1][y];
                      ans %=md;
                  }
              }
          }
      }
      for (int i=0;i<2;++i) for (int j = 0; j < n; ++j) for (int x=0; x < 4;++x)
          dp[i][j][x] = dp[i+1][j][x];
  }
  int ret = 0;
  for (int x = 0; x < 4;++x) ret = (ret + dp[2][0][x]) %md;
  return ret;
}
