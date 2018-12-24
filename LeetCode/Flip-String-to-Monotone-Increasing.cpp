/* A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: "00011000"
Output: 2
Explanation: We flip to get 00000000. */

int minFlipsMonoIncr(string S) {
  vector<int> f0(S.size() + 1), f1(S.size() + 1);
  int res = INT_MAX;
  for (auto i = 0; i < S.size(); ++i) {
      f0[i + 1] += f0[i] + (S[i] == '0' ? 0 : 1);
      f1[S.size() - i - 1] += f1[S.size() - i] + (S[S.size() - i - 1] == '0' ? 1 : 0);
  }
  for (auto i = 0; i <= S.size(); ++i) res = min(res, f0[i] + f1[i]);
  return res;
}
