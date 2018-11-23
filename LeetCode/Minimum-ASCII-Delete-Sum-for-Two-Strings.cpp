/* Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher. */

int minimumDeleteSum(string s1, string s2) {
  int m = s1.size(), n = s2.size();
  vector<int> dp(n+1, 0);
  for (int j = 1; j <= n; j++)
      dp[j] = dp[j-1]+s2[j-1];
  for (int i = 1; i <= m; i++) {
      int t1 = dp[0];
      dp[0] += s1[i-1];
      for (int j = 1; j <= n; j++) {
          int t2 = dp[j];
          dp[j] = s1[i-1] == s2[j-1]? t1:min(dp[j]+s1[i-1], dp[j-1]+s2[j-1]);
          t1 = t2;
      }
  }
  return dp[n];
}
