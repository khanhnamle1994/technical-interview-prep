// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

/* For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
] */

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    int i = 0;
    vector<int> p(k, 0);

    while(i >= 0) {
      p[i]++;
      if(p[i] > n) {
        i--;
      } else if (i == k - 1) {
        result.push_back(p);
      } else {
        i++;
        p[i] = p[i - 1];
      }
    }
    return result;
}
