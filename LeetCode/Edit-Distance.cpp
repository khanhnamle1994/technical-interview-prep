// Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

int minDistance(string word1, string word2) {
  int m = word1.length(), n = word2.length();
  vector<int> cur(m + 1, 0);

  for (int i = 1; i <= m; i++)
      cur[i] = i;

  for (int j = 1; j <= n; j++) {
      int pre = cur[0];
      cur[0] = j;
      for (int i = 1; i <= m; i++) {
          int temp = cur[i];
          if (word1[i - 1] == word2[j - 1])
              cur[i] = pre;
          else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
          pre = temp;
      }
  }
  return cur[m];
}
