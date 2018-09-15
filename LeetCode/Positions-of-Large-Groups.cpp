// In a string S of lowercase letters, these letters form consecutive groups of the same character.

// For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

// Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

// The final answer should be in lexicographic order.

/* Example 1:
Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.

Example 2:
Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.

Example 3:
Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]] */

vector<vector<int>> largeGroupPositions(string S) {
  int i = 0, j = 0, N = S.size();
  vector<vector<int>> res;
  while (j < N) {
      while (j < N && S[j] == S[i]) ++j;
      if (j - i >= 3) res.push_back({i, j - 1});
      i = j;
  }
  return res;
}
