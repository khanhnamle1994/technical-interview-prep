/* For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

Example 1:
Input: 4
Output: [2,1,4,3]

Example 2:
Input: 5
Output: [3,1,2,5,4] */

vector<int> beautifulArray(int N) {
  vector<int> res = {1};
  while (res.size() < N) {
      vector<int> tmp;
      for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
      for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
      res = tmp;
  }
  return res;
}
