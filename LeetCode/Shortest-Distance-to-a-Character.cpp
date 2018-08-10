// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

/* Example 1:
Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0] */

vector<int> shortestToChar(string S, char C) {
  int n = S.size();
  vector<int> res(n, n);
  int pos = -n;
  for (int i = 0; i < n; ++i) {
      if (S[i] == C) pos = i;
      res[i] = min(res[i], abs(i - pos));
  }
  for (int i = n - 1; i >= 0; --i) {
      if (S[i] == C)  pos = i;
      res[i] = min(res[i], abs(i - pos));
  }
  return res;
}

/* Explanation
Initial result array.
Loop twice on the string S.
First forward pass to find shortest distant to character on left.
Second backward pass to find shortest distant to character on right.

Time Complexity O(N) */
