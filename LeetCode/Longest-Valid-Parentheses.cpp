// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
/* Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()" */

int longestValidParentheses(string s) {
  int n = s.size(), ans = 0;
  vector<int> dp(n + 1,0);
  for (int i = 2; i <= n; i++) {
    if (s[i - 1] == ')') {
      if (s[i - 2] == '(') {
          dp[i] = dp[i - 2] + 2;
      } else {
          int start = i - 2 - dp[i - 1];
          if (s[start] == '(') {
            dp[i] = dp[i-1] + 2 + dp[start];
          }
      }
    }
    ans = max(ans,dp[i]);
  }
  return ans;
}
