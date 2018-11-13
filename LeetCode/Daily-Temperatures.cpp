// Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

// For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

vector<int> dailyTemperatures(vector<int>& T) {
  vector<int> res(T.size());
  for (int i = T.size() - 1; i >= 0; --i) {
      int j = i + 1;
      while (j < T.size() && T[j] <= T[i]) {
          if (res[j] > 0) j = res[j] + j;
          else j = T.size();
      }
      if (j < T.size()) res[i] = j - i;
  }
  return res;
}
