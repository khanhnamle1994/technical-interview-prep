// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
/* Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true

Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false */

bool isInterleave(string s1, string s2, string s3) {
  if (s1.length() + s2.length() != s3.length()) {
    return false;
  }

  vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
  dp[0][0] = true;

  for(int i = 0; i < s1.length(); i++)  {
    if (s3.substr(0, i + 1) == s1.substr(0, i + 1)) {
      dp[i + 1][0] = true;
    }
  }

  for(int i = 0; i < s2.length(); i++) {
    if (s3.substr(0, i + 1) == s2.substr(0, i + 1)) {
      dp[0][i + 1] = true;
    }
  }

  for(int i = 0; i < s1.length(); i++) {
      for(int j = 0; j < s2.length(); j++) {
          if (s3[i + j + 1] != s1[i] and s3[i + j + 1] != s2[j]) {
            dp[i + 1][j + 1] = false;
          }
          if (s3[i + j + 1] == s1[i]) {
            dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j + 1];
          }
          if (s3[i + j + 1] == s2[j]) {
            dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i + 1][j];
          }
      }
  }

  return dp.back().back();
}
