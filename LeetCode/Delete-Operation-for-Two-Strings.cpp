// Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

/* Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea". */

// Dynamic Programming
/* The transition function is the minimum of three cases:

* Skip character in both string (dp[i - 1][j - 1]).
>> Add two deleted characters if the character is different
>> Add zero deleted characters if the character is the same (w1[i] == w2[j])
* Skip character in the first string (dp[i - 1][j]). Add one deleted character
* Skip character in the second string (dp[i][j - 1]). Add one deleted one character */

int minDistance(string word1, string word2) {
  if (word1.size() == 0 || word2.size() == 0) {
    return word1.size() + word2.size();
  }
  vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));

  for (int i = 0; i < word1.size(); ++i) {
    for (int j = 0; j < word2.size(); ++j) {
      dp[i][j] = min((i == 0 || j == 0 ? max(i, j) : dp[i - 1][j - 1]) + (word1[i] == word2[j] ? 0 : 2),
          1 + min(i == 0 ? j + 1 : dp[i - 1][j], j == 0 ? i + 1 : dp[i][j - 1]));
    }
  }  
  return dp[word1.size() - 1][word2.size() - 1];
}
