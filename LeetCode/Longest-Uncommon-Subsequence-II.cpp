// Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

// A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

// The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

/* Example 1:
Input: "aba", "cdc", "eae"
Output: 3 */

bool isSubsequence(string s, string t, size_t si, size_t ti) {
  if (si == s.length()) {
      return true;
  }
  if (ti == t.length()) {
      return false;
  }

  return (s[si] == t[ti]) && isSubsequence(s, t, si + 1, ti + 1) || isSubsequence(s, t, si, ti + 1);
}

int findLUSlength(vector<string>& strs) {
  int n = strs.size();
  int maxlen = -1;
  for (int i = 0; i < n; i++) {
      bool uniq = true;
      for (int j = 0; j < n; j++) {
          if (i != j && isSubsequence(strs[i], strs[j], 0, 0)) {
              uniq = false;
              break;
          }
      }
      if (uniq) {
          maxlen = max(maxlen, (int)strs[i].length());
      }
  }

  return maxlen;
}
