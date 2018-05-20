/* Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial). */

/* Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false */

bool isMatch(string s, string p) {
  vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
  dp[0][0] = true;

  for(int j = 1; j <= p.size(); j++)
  {
      if(p[j-1] == '*')
          dp[0][j] = true;
      else
          break;
  }

  for (int i = 1; i <= s.size(); i++)
  {
      for (int j = 1; j <= p.size(); j++)
      {
          if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
              dp[i][j] = dp[i - 1][j - 1];
          else if (p[j - 1] == '*')
              dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
      }
  }

  return dp.back().back();
}
