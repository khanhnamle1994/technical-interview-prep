// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

/* Example 1:
Input:
"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb". */

int longestPalindromeSubseq(string s) {
  if (s.empty()) return 0;

  vector<vector<int>> longest(s.size(), vector<int>(s.size()));
  for (int len=1; len<=s.size(); len++) {
      for (int lhs=0; lhs+len<=s.size(); lhs++) {
          int rhs = lhs+len-1;
          if (lhs == rhs) {
              longest[lhs][rhs] = 1;
          } else if (lhs+1 == rhs) {
              longest[lhs][rhs] = (s[lhs] == s[rhs]) ? 2 : 1;
          } else {
              int add = s[lhs] == s[rhs] ? 2 : 0;
              longest[lhs][rhs] = max(max(longest[lhs][rhs-1], longest[lhs+1][rhs]), longest[lhs+1][rhs-1] + add);
          }
      }
  }

  return longest[0].back();
}

// The DP state longest[i][j] means for substring between [i, j] inclusive the longest palindromic subsequence.

// Basic cases:
// if i == j, then longest[i][j] = 1, naturally
// if i+1 == j, then longest[i][j] = 2 if s[i] == s[j]
// longest[i][j] = 1 otherwise

// Transition rule:
// s[i] == s[j]
// dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1] + 2)
// s[i] != s[j]
// dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1])

// The condition that only subsequence made it quite simply because at any range [i, j], the s[i], s[j] can be omitted to make the rest range
// i+1, j] or [i, j-1] our valid longest palindromic subsequence.
