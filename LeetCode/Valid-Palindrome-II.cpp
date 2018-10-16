// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

/* Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'. */

bool isp(string s, int l, int r) {
  for (int i = l, j = r; i < j; i++, j--)
      if (s[i] != s[j]) return false;
  return true;
}

bool validPalindrome(string s) {
  for (int i = 0, j = s.size() - 1; i < j; i++, j--)
      if (s[i] != s[j]) return isp(s, i + 1, j) || isp(s, i, j - 1);
  return true;
}
