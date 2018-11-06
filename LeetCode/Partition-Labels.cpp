/* A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts. */

vector<int> partitionLabels(string S) {
  vector<int> res, pos(26, 0);
  for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
  for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
    idx = max(idx, pos[S[i] - 'a']);
    if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
  }
  return res;
}
